#include <bits/stdc++.h>
using namespace std;

int n, m, cnt;
vector<int> adj[100'001];
bool vis[100'001];

void dfs(int cur) {
	vis[cur] = 1;
	for (int nxt : adj[cur]) {
		if (vis[nxt]) continue;
		dfs(nxt);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0, u, v; i < m; i++) {
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	for (int i = 1; i <= n; i++) {
		if (vis[i]) continue;
		dfs(i);
		cnt++;
	}
	cout << (cnt - 1) + ((m + cnt - 1) - (n - 1));
}