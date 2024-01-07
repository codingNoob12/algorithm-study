#include <bits/stdc++.h>
using namespace std;

int n, m;
string board[1001];
int visited[2][1001][1001];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
queue<tuple<int, int, bool>> Q;

int bfs() {
	Q.push({0, 0, 0});
	visited[0][0][0] = visited[1][0][0] = 1;

	while (!Q.empty()) {
		int x, y, is_broken;
		tie(x, y, is_broken) = Q.front();
		Q.pop();

		if (x == n - 1 && y == m - 1) return visited[is_broken][x][y];

		for (int dir = 0; dir < 4; dir++) {
			int nx = x + dx[dir];
			int ny = y + dy[dir];

			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;

			if (board[nx][ny] == '0' && visited[is_broken][nx][ny] == -1) {
				visited[is_broken][nx][ny] = visited[is_broken][x][y] + 1;
				Q.push({nx, ny, is_broken});
			} else if (!is_broken && board[nx][ny] == '1' && visited[1][nx][ny] == -1) {
				visited[1][nx][ny] = visited[is_broken][x][y] + 1;
				Q.push({nx, ny, 1});
			}
		}
	}

	return -1;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 1001; j++) fill(visited[i][j], visited[i][j] + 1001, -1);
	}

	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> board[i];

	cout << bfs();
}