#include <bits/stdc++.h>
using namespace std;

int n, r, q;
vector<int> adj[100'001];
int p[100'001], cnt[100'001];

void dfs(int cur) {
	cnt[cur]++;
	for (int nxt : adj[cur]) {
		if (p[cur] == nxt) continue;
		p[nxt] = cur;
		dfs(nxt);
		cnt[cur] += cnt[nxt];
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> r >> q;
	for (int i = 0, u, v; i < n - 1; i++) {
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	dfs(r);

	while (q--) {
		int u;
		cin >> u;
		cout << cnt[u] << "\n";
	}
}