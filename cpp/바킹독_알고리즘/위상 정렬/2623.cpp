#include <bits/stdc++.h>
using namespace std;

int n, m;
int deg[1001];
vector<int> adj[1001], res;
queue<int> q;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	while (m--) {
		int sz, u, v;
		cin >> sz >> u;
		while (--sz) {
			cin >> v;
			adj[u].push_back(v);
			deg[v]++;
			u = v;
		}
	}

	for (int i = 1; i <= n; i++) {
		if (!deg[i]) q.push(i);
	}

	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		res.push_back(cur);
		for (int nxt : adj[cur]) {
			deg[nxt]--;
			if (!deg[nxt]) q.push(nxt);
		}
	}

	if (res.size() != n) cout << 0;
	else {
		for (int e : res) cout << e << "\n";
	}
}