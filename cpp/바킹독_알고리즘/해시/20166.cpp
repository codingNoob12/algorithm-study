#include <bits/stdc++.h>
using namespace std;

int n, m, k;
string grid[1000];
unordered_map<string, int> um;
int dx[] = {1, 0, -1, 0, 1, -1, -1, 1};
int dy[] = {0, 1, 0, -1, 1, -1, 1, -1};

void bfs(int i, int j) {
	queue<tuple<int, int, string>> q;
	string init;
	init += grid[i][j];
	um[init]++;
	q.push({i, j, init});

	while (!q.empty()) {
		int x, y;
		string s;
		tie(x, y, s) = q.front();
		q.pop();

		for (int dir = 0; dir < 8; dir++) {
			int nx = x + dx[dir], ny = y + dy[dir];

			if (nx < 0) nx += n;
			else if (nx >= n) nx -= n;
			if (ny < 0) ny += m;
			else if (ny >= m) ny -= m;

			string ns = s + grid[nx][ny];
			um[ns]++;
			if (ns.length() < 5) q.push({nx, ny, ns});
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> k;
	for (int i = 0; i < n; i++) cin >> grid[i];

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) bfs(i, j);
	}
	
	for (int i = 0; i < k; i++) {
		string favorite;
		cin >> favorite;
		cout << um[favorite] << "\n";
	}
}
