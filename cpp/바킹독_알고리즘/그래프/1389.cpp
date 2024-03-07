#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> adj[101];
int dist[101][101];

int kv(int x) {
	int sum = 0;
	for (int i = 1; i <= n; i++) {
		if (dist[x][i] == -1) continue;
		sum += dist[x][i];
	}
	return sum;
}

void bfs(int x) {
	queue<int> q;
	q.push(x);
	dist[x][x] = 0;

	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		for (int nxt : adj[cur]) {
			if (dist[x][nxt] != -1) continue;
			q.push(nxt);
			dist[x][nxt] = dist[x][cur] + 1;
		}
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

	for (int i = 1; i <= n; i++) {
		fill(dist[i], dist[i] + n + 1, -1);
		bfs(i);
	}

	int idx = 1, mn = kv(idx);
	for (int i = 2; i <= n; i++) {
		int t = kv(i);
		if (mn > t) {
			mn = t;
			idx = i;
		}
	}

	cout << idx;
}