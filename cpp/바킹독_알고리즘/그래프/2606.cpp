#include <bits/stdc++.h>
using namespace std;

int n, m, cnt = -1;
vector<int> adj[101];
bool vis[101];

void dfs(int cur) {
	vis[cur] = 1;
	cnt++;
	for (int nxt : adj[cur]) {
		if (vis[nxt]) continue;
		dfs(nxt);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	dfs(1);
	cout << cnt;
}