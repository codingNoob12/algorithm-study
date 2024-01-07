#include <bits/stdc++.h>
using namespace std;

int m, n, h; // m: 열, n: 행, h: 면
int board[101][101][101];
int dist[101][101][101];
int dx[] = {1, -1, 0, 0, 0, 0};
int dy[] = {0, 0, 1, -1, 0, 0};
int dz[] = {0, 0, 0, 0, 1, -1};
queue<tuple<int, int, int>> Q;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	for (int i = 0; i < 101; i++) {
		for (int j = 0; j < 101; j++) fill(dist[i][j], dist[i][j] + 101, -1);
	}

	cin >> m >> n >> h;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < m; k++) cin >> board[i][j][k];
		}
	}

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < m; k++) {
				if (board[i][j][k] == 1) {
					dist[i][j][k] = 0;
					Q.push({j, k, i});
				}
			}
		}
	}

	while (!Q.empty()) {
		auto cur = Q.front();
		Q.pop();

		int x = get<0>(cur);
		int y = get<1>(cur);
		int z = get<2>(cur);
		for (int dir = 0; dir < 6; dir++) {
			int nx = x + dx[dir];
			int ny = y + dy[dir];
			int nz = z + dz[dir];

			if (nx < 0 || nx >= n || ny < 0 || ny >= m || nz < 0 || nz >= h) continue;
			if (board[nz][nx][ny] || dist[nz][nx][ny] >= 0) continue;

			Q.push({nx, ny, nz});
			dist[nz][nx][ny] = dist[z][x][y] + 1;
		}
	}

	int ans = 0;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < m; k++) {
				if (board[i][j][k] != -1 && dist[i][j][k] == -1) {
					cout << -1;
					return 0;
				}
				ans = max(ans, dist[i][j][k]);
			}
		}
	}

	cout << ans;
}