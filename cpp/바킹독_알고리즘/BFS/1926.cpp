#include <bits/stdc++.h>
using namespace std;

int n, m;
int image[501][501];
bool visited[501][501];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) cin >> image[i][j];
	}

	int count = 0, max_area = 0;
	queue<pair<int, int>> q;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (!image[i][j] || visited[i][j]) continue;

			visited[i][j] = true;
			q.push({i, j});
			count++;
			int area = 0;

			while (!q.empty()) {
				pair<int, int> cur = q.front();
				q.pop();
				area++;
				for (int idx = 0; idx < 4; idx++) {
					int nx = cur.first + dx[idx];
					int ny = cur.second + dy[idx];

					if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
					if (visited[nx][ny] || !image[nx][ny]) continue;
					q.push({nx, ny});
					visited[nx][ny] = true;
				}
			}

			max_area = max(area, max_area);
		}
	}

	cout << count << "\n" << max_area;
}