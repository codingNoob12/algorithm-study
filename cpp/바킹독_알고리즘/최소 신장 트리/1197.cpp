#include <bits/stdc++.h>
using namespace std;

int v, e, parent[10'001];
tuple<int, int, int> edge[100'001]; // {비용, 정점1, 정점2}

int find(int x) {
	if (parent[x] == x) return x;
	return parent[x] = find(parent[x]);
}

void merge(int x, int y) {
	x = find(x);
	y = find(y);
	if (x == y) return;
	parent[y] = x;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> v >> e;
	for (int i = 0, a, b, c; i < e; i++) {
		cin >> a >> b >> c;
		edge[i] = {c, a, b};
	}

	sort(edge, edge + e);
	for (int i = 1; i <= v; i++) parent[i] = i;

	int cnt = 0;
	long long cost = 0;
	for (int i = 0; i < e; i++) {
		int a, b, c;
		tie(c, a, b) = edge[i];
		if (find(a) == find(b)) continue;
		merge(a, b);
		cost += c;
		cnt++;
		if (cnt == v - 1) break;
	}
	cout << cost;
}