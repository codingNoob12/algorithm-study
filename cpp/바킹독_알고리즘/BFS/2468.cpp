#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;

int n;
int board[101][101];
queue<pair<int, int>> Q;
bool visited[101][101];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int bfs(int height) {
	Q = queue<pair<int, int>>();
	for (int i = 0; i < 101; i++) fill(visited[i], visited[i] + 101, 0);

	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (board[i][j] <= height || visited[i][j]) continue;
			Q.push({i, j});
			visited[i][j] = true;
			cnt++;

			while (!Q.empty()) {
				auto cur = Q.front();
				Q.pop();

				for (int dir = 0; dir < 4; dir++) {
					int nx = cur.X + dx[dir];
					int ny = cur.Y + dy[dir];

					if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
					if (board[nx][ny] <= height || visited[nx][ny]) continue;

					Q.push({nx, ny});
					visited[nx][ny] = true;
				}
			}
		}
	}

	return cnt;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	//입력 & 최소 높이 구하기
	int min_h = INT_MAX, max_h = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
			min_h = min(min_h, board[i][j]);
			max_h = max(max_h, board[i][j]);
		}
	}

	//최소 높이 - 1 ~ 최대 높이 (bfs 결과가 0) => bfs
	int ans = 0;
	for (int i = min_h - 1; i <= max_h; i++) ans = max(ans, bfs(i));

	cout << ans;
}