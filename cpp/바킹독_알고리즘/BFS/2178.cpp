#include <bits/stdc++.h>
using namespace std;

int n, m;
int board[101][101];
int dist[101][101];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
queue<pair<int, int>> Q;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	for (int i = 0; i < 101; i++) {
		fill(dist[i], dist[i] + 101, -1);
	}

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string temp;
		cin >> temp;
		for (int j = 0; j < m; j++) board[i][j] = temp[j] - '0';
	}

	Q.push({0, 0});
	dist[0][0] = 0;

	while (!Q.empty()) {
		pair<int, int> cur = Q.front();
		Q.pop();

		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.first + dx[dir];
			int ny = cur.second + dy[dir];

			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if (dist[nx][ny] >= 0 || !board[nx][ny]) continue;

			Q.push({nx, ny});
			dist[nx][ny] = dist[cur.first][cur.second] + 1;
		}
	}

	cout << dist[n - 1][m - 1] + 1;
}