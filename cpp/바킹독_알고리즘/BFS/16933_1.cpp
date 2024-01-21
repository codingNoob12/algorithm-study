#include <bits/stdc++.h>
using namespace std;

int n, m, k;
string board[1000];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
int dist[1000][1000][11][2];
queue<tuple<int, int, int, bool>> q;//{x, y, break, night}

int bfs() {
	q.push({0, 0, 0, 0});
	dist[0][0][0][0] = 1;

	while (!q.empty()) {
		int x, y, b;
		bool t;
		tie(x, y, b, t) = q.front();
		q.pop();

		if (x == n - 1 && y == m - 1) return dist[x][y][b][t];

		for (int dir = 0; dir < 4; dir++) {
			int nx = x + dx[dir];
			int ny = y + dy[dir];

			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;

			if (board[nx][ny] == '0' && dist[nx][ny][b][!t] == 0) {
				q.push({nx, ny, b, !t});
				dist[nx][ny][b][!t] = dist[x][y][b][t] + 1;
			} else if (board[nx][ny] == '1' && b < k) {
				if (t) { //밤
					if (dist[x][y][b][!t]) continue;
					q.push({x, y, b, !t});
					dist[x][y][b][!t] = dist[x][y][b][t] + 1;
				} else { //낮
					if (dist[nx][ny][b + 1][!t]) continue;
					q.push({nx, ny, b + 1, !t});
					dist[nx][ny][b + 1][!t] = dist[x][y][b][t] + 1;
				}
			}
		}
	}

	return -1;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> k;
	for (int i = 0; i < n; i++) cin >> board[i];
	cout << bfs();
}
