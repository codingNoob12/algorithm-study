#include <bits/stdc++.h>
using namespace std;

int n, m, k;
string board[1000];
int dist[11][1000][1000];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
queue<tuple<int, int, int>> q; //{x, y, break}

int bfs() {
	q.push({0, 0, 0});
	for (int i = 0; i < 11; i++) dist[i][0][0] = 0;

	while (!q.empty()) {
		int x, y, b;
		tie(x, y, b) = q.front();
		q.pop();

		if (x == n - 1 && y == m - 1) return dist[b][x][y] + 1;

		for (int dir = 0; dir < 4; dir++) {
			int nx = x + dx[dir];
			int ny = y + dy[dir];

			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if (board[nx][ny] == '0' && dist[b][nx][ny] == -1) {
				q.push({nx, ny, b});
				dist[b][nx][ny] = dist[b][x][y] + 1;
			} else if (board[nx][ny] == '1' && b < k && dist[b + 1][nx][ny] == -1) {
				q.push({nx, ny, b + 1});
				dist[b + 1][nx][ny] = dist[b][x][y] + 1;
			}
		}
	}

	return -1;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	for (int i = 0; i < 11; i++) {
		for (auto e : dist[i]) fill(e, e + 1000, -1);
	}

	cin >> n >> m >> k;
	for (int i = 0; i < n; i++) cin >> board[i];

	cout << bfs();
}