#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;

const int NOT_VISITED = -1;

const char BLANK = '.';
const char WALL = '#';
const char HOLE = 'O';

int n, m;
string board[11];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
pair<int, int> red, blue;
// dist[a][b][c][d]: 빨강=(a, b); 파랑=(c, d)일때, 이동 거리
int dist[11][11][11][11];

int bfs() {
	queue<tuple<int, int, int, int>> q;
	q.push({red.X, red.Y, blue.X, blue.Y});
	dist[red.X][red.Y][blue.X][blue.Y]++;

	while (!q.empty()) {
		int rx, ry, bx, by;
		tie(rx, ry, bx, by) = q.front();
		q.pop();

		int cnt = dist[rx][ry][bx][by];
		if (cnt >= 10) return -1;

		for (int dir = 0; dir < 4; dir++) {
			int nrx = rx, nry = ry, nbx = bx, nby = by;

			//파랑 먼저 이동 => 파랑 탈출하면 빨강은 볼필요도 없어짐.
			while (board[nbx + dx[dir]][nby + dy[dir]] == BLANK) {
				nbx += dx[dir];
				nby += dy[dir];
			}

			if (board[nbx + dx[dir]][nby + dy[dir]] == HOLE) continue;

			//빨강 이동
			while (board[nrx + dx[dir]][nry + dy[dir]] == BLANK) {
				nrx += dx[dir];
				nry += dy[dir];
			}

			if (board[nrx + dx[dir]][nry + dy[dir]] == HOLE) return cnt + 1;

			if ((nrx == nbx) && (nry == nby)) {
				switch (dir) {
					case 0: rx < bx ? nrx-- : nbx--;
						break;
					case 1: ry < by ? nry-- : nby--;
						break;
					case 2: rx < bx ? nbx++ : nrx++;
						break;
					default: ry < by ? nby++ : nry++;
				}
			}

			if (dist[nrx][nry][nbx][nby] != NOT_VISITED) continue;
			q.push({nrx, nry, nbx, nby});
			dist[nrx][nry][nbx][nby] = cnt + 1;
		}
	}

	return -1;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	for (int i = 0; i < 11; i++) {
		for (int j = 0; j < 11; j++) {
			for (int k = 0; k < 11; k++) {
				fill(dist[i][j][k], dist[i][j][k] + 11, NOT_VISITED);
			}
		}
	}

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> board[i];
		for (int j = 0; j < m; j++) {
			if (board[i][j] == 'R') {
				red = {i, j};
				board[i][j] = BLANK;
			} else if (board[i][j] == 'B') {
				blue = {i, j};
				board[i][j] = BLANK;
			}
		}
	}

	cout << bfs();
}
/*
 * 문제
 * 구슬 탈출
 * 직사각형 보드에 빨간 구슬과 파란 구슬을 1개씩 넣고, 빨간 구슬을 구멍으로 빼내는 게임
 *
 * 보드 크기: n by m.
 * 각각 1x1크기의 칸으로 나눠져 있음
 * 가장 바깥 행과 열은 모두 막혀있고 보드에 구멍이 하나 있다.
 * 구슬의 크기는 칸 1개에 꽉참 <- 문제 이의제기 막기용인듯?
 *
 * 구슬은 건드릴 수 없고, 판 기울여서 공 움직여야함
 * 왼쪽, 오른쪽, 위, 아래 방향으로 기울이기 가능
 *
 * 기울이면 공은 동시에 움직이고,
 * 빨간 구슬이 구멍에 빠지면 성공, 파란 구슬이 빠지면 실패, 동시에 빠져도 실패.
 * 두 구슬은 동시에 같은 칸에 있을 수 없다.
 * 구슬이 움직이지 않을 때 까지 보드를 기울인다.
 *
 * 보드의 상태가 주어졌을 때, 최소 몇 번만에 빨간 구슬을 구멍을 통해 빼낼 수 있는지 구해보자.
 *
 * 입력
 * N, M
 * 보드의 상태.
 * '.': 빈칸, '#': 벽, '0': 구멍, 'R': 빨간 구슬, 'B': 파란 구슬
 *
 * 보드 가장자리는 모두 벽, 구멍은 1개, 구슬은 각각 1개씩
 *
 * 출력
 * 빨간 구슬 빼내는 최소 횟수. 10번 이하로 못빼면 -1 출력
 *
 * //==아이디어==//
 * 아무래도 기울였을 때, 벽 만날때까지 구슬이 이동하는 거 같다.
 *
 * 기울이기 구현해야되고, 이거 백트래킹 같은데?
 * 10번으로 제한 걸려있으니까 각각 4방향에 대해 기울여보다가 빨간색이 먼저 구멍으로 나오는지 보면 될 듯?
 * 4^10 * 10 * (4 * 10 * 10 + 2 * 10) = 4,404,019,200로 시간 초과 나네...
 *
 * 4^10 * 10 * 2 * 10 = 209,715,200
 *
 * 최단 거리 문제와 동일하니까 bfs로 접근해도 될듯?
 * 각각 bfs를 걸게 되면, 공이 겹치는 경우를 고려하기 힘들어진다.
 * 따라서 공 2개를 한번에 이동시키도록 bfs를 구현해야 한다.
 * 그러므로, 이동거리와 큐는 4차원 정보를 저장해야 한다.
 * bfs에서 공의 좌표 조합이 n^2 * m^2이고 이것이 bfs에서 고려하는 모든 경우의 수가 된다.
 * 10 * 10 * 10 * 10 * 2 * 10(이동) = 200,000으로 1초 이내에 프로그램 종료
 */