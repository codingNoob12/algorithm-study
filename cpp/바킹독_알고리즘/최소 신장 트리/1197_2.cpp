#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;

int v, e;
vector<pair<int, int>> adj[10001]; // {비용, 정점}
priority_queue<tuple<int, int, int>,
			   vector<tuple<int, int, int>>,
			   greater<>> pq; // {비용, 정점1, 정점2}
bool chk[10001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> v >> e;
	for (int i = 0, a, b, c; i < e; i++) {
		cin >> a >> b >> c;
		adj[a].push_back({c, b});
		adj[b].push_back({c, a});
	}

	int cnt = 0;
	long long ans = 0;
	chk[1] = 1;
	for (auto nxt : adj[1]) pq.push({nxt.X, 1, nxt.Y});

	while (cnt < v - 1) {
		int c, a, b;
		tie(c, a, b) = pq.top();
		pq.pop();
		if (chk[b]) continue;
		chk[b] = 1;
		ans += c;
		cnt++;

		for (auto nxt : adj[b]) {
			if (!chk[nxt.Y]) pq.push({nxt.X, b, nxt.Y});
		}
	}
	cout << ans;
}