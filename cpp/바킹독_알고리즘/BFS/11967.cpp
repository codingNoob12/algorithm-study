#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;

const int DARK = -1;
const int NOT_VISITED = 0;
const int VISITED = 1;

int N, M, ans;
vector<pair<int, int>> board[101][101];
int vis[101][101];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
queue<pair<int, int>> q;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	for (auto e : vis) fill(e, e + 101, DARK);

	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int x, y, a, b;
		cin >> x >> y >> a >> b;
		board[x][y].push_back({a, b});
	}

	q.push({1, 1});
	vis[1][1] = VISITED;
	while (!q.empty()) {
		int x, y;
		tie(x, y) = q.front();
		q.pop();

		//불을 켜고 방문할 수 있는 지점이면 큐에 삽입
		for (auto pos : board[x][y]) {
			if (vis[pos.X][pos.Y] == VISITED) continue;
			for (int dir = 0; dir < 4; dir++) {
				int nx = pos.X + dx[dir], ny = pos.Y + dy[dir];
				if (nx < 1 || nx > N || ny < 1 || ny > N) continue;
				if (vis[nx][ny] == VISITED) {
					q.push(pos);
					vis[pos.X][pos.Y] = VISITED;
					break;
				}
			}
			if (vis[pos.X][pos.Y] != VISITED) vis[pos.X][pos.Y] = NOT_VISITED;
		}

		for (int dir = 0; dir < 4; dir++) {
			int nx = x + dx[dir], ny = y + dy[dir];
			if (nx < 1 || nx > N || ny < 1 || ny > N) continue;
			if (vis[nx][ny] != NOT_VISITED) continue;
			q.push({nx, ny});
			vis[nx][ny] = VISITED;
		}
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) ans += vis[i][j] != DARK;
	}
	cout << ans;
}