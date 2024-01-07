#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;

int n;
string board[26];
queue<pair<int, int>> Q;
bool visited[26][26];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
vector<int> areas;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	// 입력
	cin >> n;
	for (int i = 0; i < n; i++) cin >> board[i];

	// bfs + area
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (board[i][j] == '0' || visited[i][j]) continue;
			Q.push({i, j});
			visited[i][j] = true;
			int area = 1;

			while (!Q.empty()) {
				auto cur = Q.front();
				Q.pop();

				for (int dir = 0; dir < 4; dir++) {
					int nx = cur.X + dx[dir];
					int ny = cur.Y + dy[dir];

					if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
					if (board[nx][ny] == '0' || visited[nx][ny]) continue;

					Q.push({nx, ny});
					visited[nx][ny] = true;
					area++;
				}
			}

			areas.push_back(area);
		}
	}

	// sort & 출력
	sort(areas.begin(), areas.end());

	cout << areas.size() << "\n";
	for (auto e : areas) cout << e << "\n";
}