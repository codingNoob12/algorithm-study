#include <bits/stdc++.h>
using namespace std;

string board[5];
bool mask[25];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
int ans;

/*
 * next_permutation 으로 선택하려면, 1차원인 편이 편하다. 따라서 mask를 1차원으로 관리
 *
 * 선택한 이후에, 이들이 인접해있는지 확인해야함.
 * 배열을 1칸씩 이동하며 순회를 해야하므로, bfs나 dfs를 사용해야함.
 *
 * 순회하면서, 방문한 칸의 갯수는 인접한 칸의 갯수가 된다.
 * 이 값이 7이 되어야 하고, 다솜파의 수도 세서 4칸 이상인지 확인해야 한다.
 *
 * 요약)
 * 1. 전체 5x5 배열에서 7칸을 선택
 * 2. bfs로 모두 인접했는지 & 다솜파의 수가 4칸 이상인지 확인
 */
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	for (int i = 0; i < 5; i++) cin >> board[i];

	fill(mask + 7, mask + 25, true);
	do {
		queue<pair<int, int>> q;
		int adj = 0, dasom = 0;
		bool vis[5][5] = {}, isp7[5][5] = {};
		for (int i = 0; i < 25; i++) {
			if (mask[i]) continue;
			int x = i / 5, y = i % 5;
			isp7[x][y] = true;
			if (q.empty()) {
				q.push({x, y});
				vis[x][y] = true;
			}
		}
		while (!q.empty()) {
			int x, y;
			tie(x, y) = q.front();
			q.pop();
			adj++;
			dasom += board[x][y] == 'S';

			for (int dir = 0; dir < 4; dir++) {
				int nx = x + dx[dir];
				int ny = y + dy[dir];

				if (nx < 0 || nx >= 5 || ny < 0 || ny >= 5) continue;
				if (vis[nx][ny] || !isp7[nx][ny]) continue;

				q.push({nx, ny});
				vis[nx][ny] = true;
			}
		}
		if (adj == 7 && dasom >= 4) ans++;
	} while (next_permutation(mask, mask + 25));
	cout << ans << "\n";
}