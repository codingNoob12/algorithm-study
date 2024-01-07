#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;

int m, n, k;
int board[101][101];
queue<pair<int, int>> Q;
bool visited[101][101];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
vector<int> areas;

void mask(int x1, int y1, int x2, int y2) {
	for (int i = y1; i < y2; i++) {
		for (int j = x1; j < x2; j++) {
			board[i][j] = -1;
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	// 입력 & mask
	cin >> m >> n >> k;
	for (int i = 0; i < k; i++) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;

		mask(x1, y1, x2, y2);
	}

	// bfs + area
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (board[i][j] == -1 || visited[i][j]) continue;
			Q.push({i, j});
			visited[i][j] = true;
			int area = 1;

			while (!Q.empty()) {
				auto cur = Q.front();
				Q.pop();

				for (int dir = 0; dir < 4; dir++) {
					int nx = cur.X + dx[dir];
					int ny = cur.Y + dy[dir];

					if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
					if (board[nx][ny] == -1 || visited[nx][ny]) continue;

					Q.push({nx, ny});
					visited[nx][ny] = true;
					area++;
				}
			}

			areas.push_back(area);
		}
	}

	// sort
	sort(areas.begin(), areas.end());

	// 출력
	cout << areas.size() << "\n";
	for (auto e : areas) cout << e << " ";
}