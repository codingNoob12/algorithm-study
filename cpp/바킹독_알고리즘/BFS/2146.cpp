#include <bits/stdc++.h>
using namespace std;

int n;
int board[100][100];
int dist[100][100];
bool is_same_continent[100][100];
bool is_done[100][100];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

void init_is_same_continent(int r, int c) {
	queue<pair<int, int>> q;
	for (auto e : is_same_continent) fill(e, e + 100, 0);

	q.push({r, c});
	is_same_continent[r][c] = true;

	while (!q.empty()) {
		int x, y;
		tie(x, y) = q.front();
		q.pop();

		for (int dir = 0; dir < 4; dir++) {
			int nx = x + dx[dir];
			int ny = y + dy[dir];

			if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
			if (!board[nx][ny] || is_same_continent[nx][ny]) continue;

			q.push({nx, ny});
			is_same_continent[nx][ny] = true;
		}
	}
}

int bfs(int r, int c) {
	int res = INT_MAX;
	queue<pair<int, int>> q;
	for (auto e : dist) fill(e, e + 100, 0);

	q.push({r, c});
	dist[r][c] = 1;

	while (!q.empty()) {
		int x, y;
		tie(x, y) = q.front();
		q.pop();

		for (int dir = 0; dir < 4; dir++) {
			int nx = x + dx[dir];
			int ny = y + dy[dir];

			if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
			if (board[nx][ny]) {
				if (!is_same_continent[nx][ny]) res = min(res, dist[x][y]);
				continue;
			}
			if (dist[nx][ny]) continue;

			q.push({nx, ny});
			dist[nx][ny] = dist[x][y] + 1;
		}
	}

	return res;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) cin >> board[i][j];
	}

	int ans = INT_MAX;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!board[i][j]) continue;
			init_is_same_continent(i, j);
			for (int dir = 0; dir < 4; dir++) {
				int nx = i + dx[dir];
				int ny = j + dy[dir];

				if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
				if (board[nx][ny] || is_done[nx][ny]) continue;
				ans = min(ans, bfs(nx, ny));
				is_done[nx][ny] = true;
			}
		}
	}
	cout << ans;
}