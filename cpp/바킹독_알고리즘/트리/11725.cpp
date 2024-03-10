#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> adj[100'001];
int parent[100'001];

void bfs() {
	queue<int> q;
	q.push(1);

	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		for (int nxt : adj[cur]) {
			if (parent[cur] == nxt) continue;
			q.push(nxt);
			parent[nxt] = cur;
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0, u, v; i < n - 1; i++) {
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	bfs();

	for (int i = 2; i <= n; i++) cout << parent[i] << "\n";
}