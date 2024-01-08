#include <bits/stdc++.h>
using namespace std;

int K, W, H;
int board[201][201];
queue<tuple<int, int, int>> Q;
int vis[32][200][200];
int dmx[] = {1, 0, -1, 0};
int dmy[] = {0, 1, 0, -1};
int dkx[] = {1, 2, 2, 1, -1, -2, -2, -1};
int dky[] = {-2, -1, 1, 2, 2, 1, -1, -2};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> K >> W >> H;
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) cin >> board[i][j];
	}

	Q.push({0, 0, 0});
	vis[0][0][0] = 1;

	while (!Q.empty()) {
		int k, x, y;
		tie(k, x, y) = Q.front();
		Q.pop();

		if (k <= K) {
			for (int dir = 0; dir < 8; dir++) {
				int nx = x + dkx[dir];
				int ny = y + dky[dir];

				if (nx < 0 || nx >= H || ny < 0 || ny >= W) continue;
				if (board[nx][ny] || vis[k + 1][nx][ny]) continue;

				Q.push({k + 1, nx, ny});
				vis[k + 1][nx][ny] = vis[k][x][y] + 1;
			}
		}

		for (int dir = 0; dir < 4; dir++) {
			int nx = x + dmx[dir];
			int ny = y + dmy[dir];

			if (nx < 0 || nx >= H || ny < 0 || ny >= W) continue;
			if (board[nx][ny] || vis[k][nx][ny]) continue;

			Q.push({k, nx, ny});
			vis[k][nx][ny] = vis[k][x][y] + 1;
		}
	}

	int ans = INT_MAX;
	for (int i = 0; i <= K; i++) {
		if (vis[i][H - 1][W - 1]) ans = min(ans, vis[i][H - 1][W - 1]);
	}
	if (ans != INT_MAX) cout << ans - 1;
	else cout << -1;
}