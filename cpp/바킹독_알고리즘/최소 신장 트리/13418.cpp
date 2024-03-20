#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n, m;
vector<tuple<int, int, int>> edge;
vector<int> p;

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

ll kruskal(int dir) {
	if (dir) reverse(edge.begin(), edge.end());
	ll cnt = 0, cost = 0;
	p = vector<int>(1001, -1);
	for (int i = 0, a, b, c; i < m + 1; i++) {
		tie(c, a, b) = edge[i];
		if (find(a) == find(b)) continue;
		merge(a, b);
		cost += c;
		cnt++;
		if (cnt == n) break;
	}
	return cost * cost;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0, a, b, c; i < m + 1; i++) {
		cin >> a >> b >> c;
		edge.push_back({1 - c, a, b});
	}
	sort(edge.begin(), edge.end());
	cout << abs(kruskal(0) - kruskal(1));
}