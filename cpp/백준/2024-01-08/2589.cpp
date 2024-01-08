#include <bits/stdc++.h>
using namespace std;

int n, m;
string board[51];
int dist[51][51];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int bfs(int i, int j) {
	queue<pair<int, int>> q;
	for (int idx = 0; idx < 51; idx++) fill(dist[idx], dist[idx] + 51, -1);

	q.push({i, j});
	dist[i][j] = 0;
	int res = 0;

	while (!q.empty()) {
		int x, y;
		tie(x, y) = q.front();
		q.pop();

		for (int dir = 0; dir < 4; dir++) {
			int nx = x + dx[dir];
			int ny = y + dy[dir];

			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if (board[nx][ny] == 'W' || dist[nx][ny] != -1) continue;

			q.push({nx, ny});
			dist[nx][ny] = dist[x][y] + 1;
			res = max(res, dist[nx][ny]);
		}
	}

	return res;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> board[i];

	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (board[i][j] == 'L') {
				ans = max(ans, bfs(i, j));
			}
		}
	}
	cout << ans;
}