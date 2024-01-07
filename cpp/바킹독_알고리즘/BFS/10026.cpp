#include <bits/stdc++.h>
using namespace std;

int n;
char board[101][101];
bool visited[101][101];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int bfs(char colors[], size_t size) {
	queue<pair<int, int>> Q;
	int cnt = 0;

	for (int i = 0; i < 101; i++) fill(visited[i], visited[i] + 101, 0);

	if (size == 2) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (board[i][j] == 'G') board[i][j] = 'R';
			}
		}
	}

	for (int idx = 0; idx < size; idx++) {
		char color = colors[idx];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (board[i][j] == color && !visited[i][j]) {
					Q.push({i, j});
					visited[i][j] = true;
					cnt++;

					while (!Q.empty()) {
						auto cur = Q.front();
						Q.pop();

						for (int dir = 0; dir < 4; dir++) {
							int nx = cur.first + dx[dir];
							int ny = cur.second + dy[dir];

							if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
							if (board[nx][ny] != color || visited[nx][ny]) continue;

							Q.push({nx, ny});
							visited[nx][ny] = true;
						}
					}
				}
			}
		}
	}

	return cnt;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		string temp;
		cin >> temp;
		for (int j = 0; j < n; j++) board[i][j] = temp[j];
	}

	cout << bfs(new char[]{'R', 'G', 'B'}, 3) << " "
		 << bfs(new char[]{'R', 'B'}, 2);
}
