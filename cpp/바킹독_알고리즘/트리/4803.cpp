#include <bits/stdc++.h>
using namespace std;

int n, m;

bool bfs(int st, vector<int> (&adj)[501], int p[], bool vis[]) {
	bool ret = 1;
	queue<int> q;
	q.push(st);
	vis[st] = 1;
	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		for (int nxt : adj[cur]) {
			if (p[cur] == nxt) continue;
			if (vis[nxt]) {
				ret = 0;
				continue;
			}
			q.push(nxt);
			p[nxt] = cur;
			vis[nxt] = 1;
		}
	}
	return ret;
}

int solve(vector<int> (&adj)[501]) {
	int cnt = 0, p[501];
	bool vis[501] = {};
	for (int i = 1; i <= n; i++) {
		if (vis[i]) continue;
		if (bfs(i, adj, p, vis)) cnt++;
	}
	return cnt;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	for (int tc = 1;; tc++) {
		cin >> n >> m;
		if (n == 0 && m == 0) break;
		vector<int> adj[501];
		for (int i = 0, u, v; i < m; i++) {
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}

		int cnt = solve(adj);
		cout << "Case " << tc << ": ";
		switch (cnt) {
			case 0: cout << "No trees.";
				break;
			case 1: cout << "There is one tree.";
				break;
			default: cout << "A forest of " << cnt << " trees.";
		}
		cout << "\n";
	}
}