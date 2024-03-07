#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> adj[100]; // 각 구슬들의 대소관계가 주어졌을 때, 그래프로 표현
int cnt[100][2]; // 각 구슬마다 가볍고, 무거운 다른 구슬들을 갯수를 관리

void bfs(int st) {
	queue<int> q;
	bool vis[100] = {};

	q.push(st);
	vis[st] = 1;

	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		for (int nxt : adj[cur]) {
			if (vis[nxt]) continue;
			q.push(nxt);
			vis[nxt] = 1;
			cnt[st][1]++;
			cnt[nxt][0]++;
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0, u, v; i < m; i++) {
		cin >> u >> v;
		adj[v].push_back(u);
	}

	for (int i = 1; i <= n; i++) bfs(i);

	int ans = 0;
	for (int i = 1; i <= n; i++) {
		if (max(cnt[i][0], cnt[i][1]) >= (n + 1) / 2) ans++;
	}
	cout << ans;
}