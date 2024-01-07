#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;

int tc;
int visited[301][301];
queue<pair<int, int>> Q;
int dx[] = {1, 2, 2, 1, -1, -2, -2, -1};
int dy[] = {-2, -1, 1, 2, 2, 1, -1, -2};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> tc;
	while (tc-- > 0) {
		int l, x, y, u, v;
		cin >> l >> x >> y >> u >> v;

		Q = queue<pair<int, int>>();
		for (int i = 0; i < 301; i++) fill(visited[i], visited[i] + 301, -1);
		pair<int, int> target = {u, v};

		Q.push({x, y});
		visited[x][y] = 0;

		while (!Q.empty() && Q.front() != target) {
			auto cur = Q.front();
			Q.pop();

			for (int dir = 0; dir < 8; dir++) {
				int nx = cur.X + dx[dir];
				int ny = cur.Y + dy[dir];

				if (nx < 0 || nx >= l || ny < 0 || ny >= l) continue;
				if (visited[nx][ny] != -1) continue;

				Q.push({nx, ny});
				visited[nx][ny] = visited[cur.X][cur.Y] + 1;
			}
		}

		cout << visited[Q.front().X][Q.front().Y] << "\n";
	}
}