#include <bits/stdc++.h>
using namespace std;

int k, V, E;
vector<int> adj[20'001];

bool bfs() {
	queue<int> q;
	vector<int> vis(V + 1, -1);
	for (int i = 1; i <= V; i++) {
		if (vis[i] != -1) continue;
		q.push(i);
		vis[i] = 0;

		while (!q.empty()) {
			int cur = q.front();
			q.pop();

			for (int nxt : adj[cur]) {
				if (vis[nxt] != -1) {
					if (vis[nxt] == vis[cur]) return 0;
					continue;
				}
				q.push(nxt);
				vis[nxt] = (vis[cur] + 1) % 2;
			}
		}
	}

	return 1;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> k;
	while (k--) {
		cin >> V >> E;
		for (int i = 1; i <= V; i++) adj[i].clear();

		for (int i = 0; i < E; i++) {
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}

		cout << (bfs() ? "YES" : "NO") << "\n";
	}
}