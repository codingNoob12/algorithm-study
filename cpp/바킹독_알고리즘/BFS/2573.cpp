#include <bits/stdc++.h>
using namespace std;

int n, m;
int heights[300][300];
int sub[300][300];
bool visited[300][300];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int adjoint_zeros(int x, int y) {
	int cnt = 0;
	for (int dir = 0; dir < 4; dir++) {
		int nx = x + dx[dir];
		int ny = y + dy[dir];

		if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
		if (heights[nx][ny] <= 0) cnt++;
	}
	return cnt;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) cin >> heights[i][j];
	}

	int ans = 0;
	bool is_done;
	while (true) {
		queue<pair<int, int>> q;
		for (int i = 0; i < 300; i++) fill(visited[i], visited[i] + 300, 0);
		for (int i = 0; i < 300; i++) fill(sub[i], sub[i] + 300, 0);

		is_done = true;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (heights[i][j] > 0) {
					is_done = false;
					break;
				}
			}
			if (!is_done) break;
		}

		if (is_done) break;

		int cnt = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (heights[i][j] <= 0 || visited[i][j]) continue;
				q.push({i, j});
				sub[i][j] = adjoint_zeros(i, j);
				visited[i][j] = true;
				cnt++;

				while (!q.empty()) {
					int x, y;
					tie(x, y) = q.front();
					q.pop();

					for (int dir = 0; dir < 4; dir++) {
						int nx = x + dx[dir];
						int ny = y + dy[dir];

						if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
						if (heights[nx][ny] <= 0 || visited[nx][ny]) continue;

						q.push({nx, ny});
						sub[nx][ny] = adjoint_zeros(nx, ny);
						visited[nx][ny] = true;
					}
				}
			}
		}

		if (cnt >= 2) break;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) heights[i][j] -= sub[i][j];
		}

		ans++;
	}

	if (is_done) cout << 0;
	else cout << ans;
}