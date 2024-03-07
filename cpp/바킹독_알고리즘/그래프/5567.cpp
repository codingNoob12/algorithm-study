#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> adj[501];
queue<int> q;
int dist[501];

void bfs() {
	q.push(1);
	dist[1] = 0;

	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		for (int nxt : adj[cur]) {
			if (dist[nxt] != -1) continue;
			q.push(nxt);
			dist[nxt] = dist[cur] + 1;
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0, a, b; i < m; i++) {
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	fill(dist, dist + n + 1, -1);
	bfs();
	int ans = 0;
	for (int i = 2; i <= n; i++) {
		if (dist[i] != -1 && dist[i] <= 2) ans++;
	}
	cout << ans;
}