#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> adj[1001];
stack<int> s;
bool vis[1001];

int dfs() {
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		if (vis[i]) continue;
		s.push(i);
		vis[i] = 1;
		cnt++;

		while (!s.empty()) {
			int cur = s.top();
			s.pop();

			for (int nxt : adj[cur]) {
				if (vis[nxt]) continue;
				s.push(nxt);
				vis[nxt] = 1;
			}
		}
	}
	return cnt;
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

	cout << dfs();
}