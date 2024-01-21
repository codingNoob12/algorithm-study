#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;

int N, M, ans;
vector<pair<int, int>> adj[101][101];
bool light[101][101];
bool vis[101][101];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
queue<pair<int, int>> q;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int x, y, a, b;
		cin >> x >> y >> a >> b;
		adj[x][y].push_back({a, b});
	}

	q.push({1, 1});
	light[1][1] = 1;
	vis[1][1] = 1;
	while (!q.empty()) {
		int x, y;
		tie(x, y) = q.front();
		q.pop();

		//불을 켜고 방문할 수 있는 지점이면 큐에 삽입
		for (auto pos : adj[x][y]) {
			if (vis[pos.X][pos.Y]) continue;
			// 해당 지점 근처에 방문했던 칸이 있으면 이곳도 방문 가능
			for (int dir = 0; dir < 4; dir++) {
				int nx = pos.X + dx[dir], ny = pos.Y + dy[dir];
				if (nx < 1 || nx > N || ny < 1 || ny > N) continue;
				if (vis[nx][ny]) {
					q.push(pos);
					vis[pos.X][pos.Y] = 1;
					break;
				}
			}
			light[pos.X][pos.Y] = 1;
		}

		for (int dir = 0; dir < 4; dir++) {
			int nx = x + dx[dir], ny = y + dy[dir];
			if (nx < 1 || nx > N || ny < 1 || ny > N) continue;
			if (vis[nx][ny] || !light[nx][ny]) continue;
			q.push({nx, ny});
			vis[nx][ny] = 1;
		}
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) ans += light[i][j];
	}
	cout << ans;
}