#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<pair<int, int>> adj[1001];
int dist[1001][1001];

void bfs() {
	for (auto e : dist) fill(e, e + n + 1, -1);
	queue<int> q;

	for (int i = 1; i <= n; i++) {
		q.push(i);
		dist[i][i] = 0;
		while (!q.empty()) {
			int cur = q.front();
			q.pop();

			for (auto p : adj[cur]) {
				int nxt, cost;
				tie(nxt, cost) = p;
				if (dist[i][nxt] != -1) continue;
				q.push(nxt);
				dist[i][nxt] = dist[i][cur] + cost;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n - 1; i++) {
		int u, v, c;
		cin >> u >> v >> c;
		adj[u].push_back({v, c});
		adj[v].push_back({u, c});
	}

	bfs();

	while (m--) {
		int u, v;
		cin >> u >> v;
		cout << dist[u][v] << "\n";
	}
}