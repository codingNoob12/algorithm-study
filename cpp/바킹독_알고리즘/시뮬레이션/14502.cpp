#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;

const int BLANK = 0;
const int WALL = 1;
const int VIRUS = 2;

int n, m;
int board1[8][8];
int board2[8][8];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
vector<pair<int, int>> virus;

void bfs() {
	queue<pair<int, int>> q;

	for (auto v : virus) {
		q.push(v);
	}

	while (!q.empty()) {
		int x, y;
		tie(x, y) = q.front();
		q.pop();

		for (int dir = 0; dir < 4; dir++) {
			int nx = x + dx[dir], ny = y + dy[dir];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if (board2[nx][ny] != BLANK) continue;
			q.push({nx, ny});
			board2[nx][ny] = VIRUS;
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board1[i][j];
			if (board1[i][j] == VIRUS) virus.push_back({i, j});
		}
	}

	int ans = 0;
	vector<int> mask(n * m);
	fill(next(mask.begin(), 3), mask.end(), 1);
	do {
		for (int i = 0; i < n; i++) copy(board1[i], board1[i] + m, board2[i]);

		bool is_valid = 1;
		for (int i = 0; i < mask.size(); i++) {
			if (mask[i]) continue;
			if (board2[i / m][i % m] != BLANK) {
				is_valid = 0;
				break;
			}
			board2[i / m][i % m] = WALL;
		}

		if (!is_valid) continue;

		bfs();

		int cnt = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) cnt += board2[i][j] == BLANK;
		}
		ans = max(ans, cnt);
	} while (next_permutation(mask.begin(), mask.end()));

	cout << ans;
}
/*
 * 문제
 * 연구소에서 바이러스가 유출됨. 확산을 막기 위해 연구소에 벽을 세우려 한다.
 * 연구소의 크기는 n by m의 직사각형; 1x1 크기의 정사각형으로 나뉘어 있음.
 * 연구소는 빈칸, 벽으로 이루어져 있으며, 벽은 1칸을 차지함
 * 바이러스는 인접한 칸으로 퍼져나갈 수 있다.
 * 새로 세울 수 있는 벽의 개수는 3개이며, 꼭 3개를 세워야한다.
 *
 * 입력
 * n, m
 * 0: 빈칸, 1: 벽, 2: 바이러스
 *
 * 출력
 * 안전 영역의 최대 크기
 *
 * //==아이디어==//
 * 이거 빈칸중에 3개 선택해서 벽세우고 bfs로 완탐한 다음 안전영역 구하는 문제 같은데?
 * 64C3 * 8 * 8 = 2,666,496로 1초 이내에 가능할듯?
 * 그냥 next_permutation을 이용해서 64개중 3개를 선택하도록 하고, 선택된 좌표중 빈칸이 아닌 곳이 존재하면
 * 다음으로 넘어가게 하면 되고, 빈칸이면 벽으로 바꾸고 bfs 쓰면 될듯?
 */