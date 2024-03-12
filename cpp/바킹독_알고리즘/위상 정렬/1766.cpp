#include <bits/stdc++.h>
using namespace std;

int n, m, deg[32001];
vector<int> adj[32001];
priority_queue<int, vector<int>, greater<>> pq;

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
		if (!deg[i]) pq.push(i);
	}

	while (!pq.empty()) {
		int cur = pq.top();
		pq.pop();
		cout << cur << " ";
		for (int nxt : adj[cur]) {
			deg[nxt]--;
			if (!deg[nxt]) pq.push(nxt);
		}
	}
}