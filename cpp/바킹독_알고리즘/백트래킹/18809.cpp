#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;

// bfs의 vis배열 status
const int EMPTY = 0;
const int GREEN = 1;
const int RED = 2;
const int FLOWER = 3;

int n, m, g, r;
int board[50][50];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

vector<pair<int, int>> candidates;
vector<int> S; // 배양액 떨어뜨릴 칸 선택

int bfs() {
	int cnt = 0;
	pair<int, int> vis[50][50]; // {time, status}
	for (int i = 0; i < 50; i++) {
		for (int j = 0; j < 50; j++) vis[i][j] = {-1, EMPTY};
	}

	queue<pair<int, int>> q;
	for (int i = 0; i < S.size(); i++) {
		if (!S[i]) continue;
		int x, y;
		tie(x, y) = candidates[i];
		q.push(candidates[i]);
		vis[x][y] = {0, S[i]};
	}

	while (!q.empty()) {
		int x, y;
		tie(x, y) = q.front();
		q.pop();
		int c = vis[x][y].Y;
		if (c == FLOWER) continue;

		int nt = vis[x][y].X + 1;
		for (int dir = 0; dir < 4; dir++) {
			int nx = x + dx[dir];
			int ny = y + dy[dir];

			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if (board[nx][ny] == 0) continue;
			if (vis[nx][ny].Y == FLOWER || vis[nx][ny].Y == c) continue;

			if (vis[nx][ny].Y == EMPTY) {
				q.push({nx, ny});
				vis[nx][ny] = {nt, c};
			} else if (nt == vis[nx][ny].X) {
				cnt++;
				vis[nx][ny].Y = FLOWER;
			}
		}
	}

	return cnt;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> g >> r;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
			if (board[i][j] == 2) {
				candidates.push_back({i, j});
				S.push_back(0);
			}
		}
	}
	fill(prev(S.end(), r), S.end(), RED);
	fill(prev(S.end(), g + r), prev(S.end(), r), GREEN);
	int ans = 0;
	do {
		ans = max(ans, bfs());
	} while (next_permutation(S.begin(), S.end()));
	cout << ans;
}
/*
 * 조건
 * - 하얀색: 배양액 x
 * - 노란색: 배양액 o
 * - 하늘색: 호수
 * 초록색과 빨간색 배양액이 동시에 도착 -> 꽃
 *
 * 배양액만 인접 빈칸으로 이동
 *
 * 피울 수 있는 꽃의 최대 갯수 구하기
 *
 * 시작점 선택 + bfs
 *
 * 빈칸이거나 색깔이 다른 칸이면 방문해보면 된다.
 *
 * 입력
 * 행의 개수(N), 열의 개수(M), 초록색 배양액 수(G), 빨간색 배양액 수(R)
 * 밭 정보(NxM) 0: 호수, 1: 배양액 x, 2: 배양액 o
 */