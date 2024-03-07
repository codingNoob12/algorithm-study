#include <bits/stdc++.h>
using namespace std;

const int NOT_VISITED = -1;

int n, mn = 0x7f7f7f7f;
vector<int> adj[51];
vector<int> candidates;

void bfs(int st) {
	queue<int> q;
	int vis[51] = {}, score = 0;
	fill(vis, vis + n + 1, NOT_VISITED);

	q.push(st);
	vis[st] = 0;

	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		for (int nxt : adj[cur]) {
			if (vis[nxt] != NOT_VISITED) continue;
			q.push(nxt);
			vis[nxt] = vis[cur] + 1;
			score = max(score, vis[nxt]);
		}
	}

	if (score == mn) candidates.push_back(st);
	else if (score < mn) {
		mn = score;
		candidates.clear();
		candidates.push_back(st);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	while (1) {
		int u, v;
		cin >> u >> v;
		if (u == -1 && v == -1) break;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	for (int i = 1; i <= n; i++) bfs(i);
	cout << mn << " " << candidates.size() << "\n";
	for (int c : candidates) cout << c << " ";
}