#include <bits/stdc++.h>
#define X get<0>
#define Y get<1>
#define Z get<2>
using namespace std;

int l, r, c;
string building[31][31];
int visited[31][31][31];
queue<tuple<int, int, int>> Q;
int dx[] = {1, -1, 0, 0, 0, 0};
int dy[] = {0, 0, 1, -1, 0, 0};
int dz[] = {0, 0, 0, 0, 1, -1};

void init() {
	for (int i = 0; i < 31; i++) {
		for (int j = 0; j < 31; j++) fill(visited[i][j], visited[i][j] + 31, -1);
	}
	Q = queue<tuple<int, int, int>>();
}

void bfs() {
	while (!Q.empty()) {
		auto cur = Q.front();
		Q.pop();

		if (building[X(cur)][Y(cur)][Z(cur)] == 'E') {
			cout << "Escaped in " << visited[X(cur)][Y(cur)][Z(cur)]
				 << " minute(s)." << "\n";
			return;
		}

		for (int dir = 0; dir < 6; dir++) {
			int nx = X(cur) + dx[dir];
			int ny = Y(cur) + dy[dir];
			int nz = Z(cur) + dz[dir];

			if (nx < 0 || nx >= l || ny < 0 || ny >= r || nz < 0 || nz >= c) continue;
			if (building[nx][ny][nz] == '#' || visited[nx][ny][nz] != -1) continue;

			Q.push({nx, ny, nz});
			visited[nx][ny][nz] = visited[X(cur)][Y(cur)][Z(cur)] + 1;
		}
	}

	cout << "Trapped!" << "\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	while (true) {
		init();

		cin >> l >> r >> c;
		if (l == 0 && r == 0 && c == 0) break;
		for (int i = 0; i < l; i++) {
			for (int j = 0; j < r; j++) {
				cin >> building[i][j];
				for (int k = 0; k < c; k++) {
					if (building[i][j][k] == 'S') {
						Q.push({i, j, k});
						visited[i][j][k] = 0;
					}
				}
			}
		}

		bfs();
	}
}