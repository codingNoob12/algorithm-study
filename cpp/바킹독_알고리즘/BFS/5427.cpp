#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;

int tc;
string board[1001];
int dist1[1001][1001]; // 불의 전파 시간
int dist2[1001][1001]; // 상근이의 이동 시간
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
queue<pair<int, int>> Q1;
queue<pair<int, int>> Q2;

void bfs(int w, int h) {
	//불에 대한 bfs
	while (!Q1.empty()) {
		auto cur = Q1.front();
		Q1.pop();

		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];

			if (nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
			if (board[nx][ny] == '#' || dist1[nx][ny] != -1) continue;

			Q1.push({nx, ny});
			dist1[nx][ny] = dist1[cur.X][cur.Y] + 1;
		}
	}

	//상근이에 대한 bfs
	while (!Q2.empty()) {
		auto cur = Q2.front();
		Q2.pop();

		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];

			if (nx < 0 || nx >= h || ny < 0 || ny >= w) {
				cout << dist2[cur.X][cur.Y] + 1 << "\n";
				return;
			}
			if (board[nx][ny] == '#' || dist2[nx][ny] != -1) continue;
			if (dist1[nx][ny] != -1 && dist1[nx][ny] <= dist2[cur.X][cur.Y] + 1) continue;

			Q2.push({nx, ny});
			dist2[nx][ny] = dist2[cur.X][cur.Y] + 1;
		}
	}

	cout << "IMPOSSIBLE\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> tc;
	while (tc-- > 0) {
		int w, h;
		cin >> w >> h;
		for (int i = 0; i < h; i++) cin >> board[i];

		for (int i = 0; i < h; i++) {
			fill(dist1[i], dist1[i] + 1001, -1);
			fill(dist2[i], dist2[i] + 1001, -1);
		}

		Q1 = queue<pair<int, int>>();
		Q2 = queue<pair<int, int>>();

		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (board[i][j] == '*') {
					dist1[i][j] = 0;
					Q1.push({i, j});
				} else if (board[i][j] == '@') {
					dist2[i][j] = 0;
					Q2.push({i, j});
				}
			}
		}

		bfs(w, h);
	}
}