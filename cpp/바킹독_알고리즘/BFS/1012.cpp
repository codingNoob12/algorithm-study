#include <bits/stdc++.h>
using namespace std;

int t;
int board[51][51];
bool visited[51][51];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;
	while (t-- > 0) {
		int m, n, k, cnt = 0;
		cin >> m >> n >> k;
		queue<pair<int, int>> Q;

		for (int i = 0; i < n; i++) {
			fill(board[i], board[i] + 51, 0);
			fill(visited[i], visited[i] + 51, 0);
		}

		for (int i = 0; i < k; i++) {
			int x, y;
			cin >> x >> y;
			board[y][x] = 1;
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (board[i][j] && !visited[i][j]) {
					Q.push({i, j});
					visited[i][j] = true;
					cnt++;

					while (!Q.empty()) {
						auto cur = Q.front();
						Q.pop();

						for (int dir = 0; dir < 4; dir++) {
							int nx = cur.first + dx[dir];
							int ny = cur.second + dy[dir];

							if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
							if (!board[nx][ny] || visited[nx][ny]) continue;

							Q.push({nx, ny});
							visited[nx][ny] = true;
						}
					}
				}
			}
		}

		cout << cnt << "\n";
	}
}