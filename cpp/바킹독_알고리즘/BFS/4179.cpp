#include <bits/stdc++.h>
using namespace std;

int r, c;
string board[1001];
int dist1[1001][1001]; // 불의 전파 시간
int dist2[1001][1001]; // 지훈이의 이동 시간
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
queue<pair<int, int>> Q1;
queue<pair<int, int>> Q2;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	for (int i = 0; i < 1001; i++) {
		fill(dist1[i], dist1[i] + 1001, -1);
		fill(dist2[i], dist2[i] + 1001, -1);
	}

	cin >> r >> c;
	for (int i = 0; i < r; i++) cin >> board[i];

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (board[i][j] == 'J') {
				dist2[i][j] = 0;
				Q2.push({i, j});
			} else if (board[i][j] == 'F') {
				dist1[i][j] = 0;
				Q1.push({i, j});
			}
		}
	}

	// 불에 대한 bfs
	while (!Q1.empty()) {
		auto cur = Q1.front();
		Q1.pop();

		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.first + dx[dir];
			int ny = cur.second + dy[dir];

			if (nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
			if (board[nx][ny] == '#' || dist1[nx][ny] >= 0) continue;

			Q1.push({nx, ny});
			dist1[nx][ny] = dist1[cur.first][cur.second] + 1;
		}
	}

	// 지훈이에 대한 bfs
	while (!Q2.empty()) {
		auto cur = Q2.front();
		Q2.pop();

		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.first + dx[dir];
			int ny = cur.second + dy[dir];

			if (nx < 0 || nx >= r || ny < 0 || ny >= c) {
				cout << dist2[cur.first][cur.second] + 1;
				return 0;
			}
			if (board[nx][ny] == '#' || dist2[nx][ny] >= 0) continue;
			if (dist1[nx][ny] != -1 && dist1[nx][ny] <= dist2[cur.first][cur.second] + 1) continue;

			Q2.push({nx, ny});
			dist2[nx][ny] = dist2[cur.first][cur.second] + 1;
		}
	}

	cout << "IMPOSSIBLE";
}