#include <bits/stdc++.h>
using namespace std;

int n, m, v;
vector<int> adj[1001];
queue<int> q;
stack<int> s;
bool vis[1001];

void dfs() {
	s.push(v);

	while (!s.empty()) {
		int cur = s.top();
		s.pop();

		if (vis[cur]) continue;
		vis[cur] = 1;
		cout << cur << " ";

		for (int i = (int)adj[cur].size() - 1; i >= 0; i--) {
			int nxt = adj[cur][i];
			if (vis[nxt]) continue;
			s.push(nxt);
		}
	}
}

void bfs() {
	q.push(v);
	vis[v] = 1;

	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		cout << cur << " ";

		for (int nxt : adj[cur]) {
			if (vis[nxt]) continue;
			q.push(nxt);
			vis[nxt] = 1;
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> v;
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	for (int i = 1; i <= n; i++) sort(adj[i].begin(), adj[i].end());

	dfs();
	cout << "\n";
	fill(vis, vis + n + 1, 0);
	bfs();
}