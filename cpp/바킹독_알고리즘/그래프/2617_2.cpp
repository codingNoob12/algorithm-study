#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> heavy[100], light[100];
bool vis[100];

bool bfs(int st, vector<int> (&adj)[100]) {
	fill(vis, vis + n + 1, 0);
	queue<int> q;
	int cnt = 0;

	q.push(st);
	vis[st] = 1;

	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		for (int nxt : adj[cur]) {
			if (vis[nxt]) continue;
			q.push(nxt);
			vis[nxt] = 1;
			cnt++;
		}
	}

	return cnt >= (n + 1) / 2;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0, u, v; i < m; i++) {
		cin >> u >> v;
		heavy[v].push_back(u);
		light[u].push_back(v);
	}

	int ans = 0;
	for (int i = 1; i <= n; i++) {
		if (bfs(i, heavy) || bfs(i, light)) ans++;
	}
	cout << ans;
}