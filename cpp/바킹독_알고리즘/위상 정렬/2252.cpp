#include <bits/stdc++.h>
using namespace std;

int n, m;
int deg[32'001];
vector<int> adj[32'001];
queue<int> q;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0, u, v; i < m; i++) {
		cin >> u >> v;
		adj[u].push_back(v);
		deg[v]++;
	}

	for (int i = 1; i <= n; i++) {
		if (!deg[i]) q.push(i);
	}

	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		cout << cur << " ";

		for (int nxt : adj[cur]) {
			deg[nxt]--;
			if (!deg[nxt]) q.push(nxt);
		}
	}
}