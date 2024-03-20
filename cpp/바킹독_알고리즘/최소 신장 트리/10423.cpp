#include <bits/stdc++.h>
using namespace std;

int n, m, k, ans, cnt;
vector<tuple<int, int, int>> edge;
vector<int> p(1002, -1);

int find(int x) {
	if (p[x] < 0) return x;
	return p[x] = find(p[x]);
}

void merge(int x, int y) {
	x = find(x);
	y = find(y);
	if (x == y) return;
	p[y] = x;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> k;
	for (int i = 0, power; i < k; i++) {
		cin >> power;
		edge.push_back({0, power, n + 1});
	}
	for (int i = 0, u, v, w; i < m; i++) {
		cin >> u >> v >> w;
		edge.push_back({w, u, v});
	}
	sort(edge.begin(), edge.end());

	for (int i = 0, u, v, w; i < edge.size(); i++) {
		tie(w, u, v) = edge[i];
		if (find(u) == find(v)) continue;
		merge(u, v);
		ans += w;
		cnt++;
		if (cnt == n) break;
	}
	cout << ans;
}