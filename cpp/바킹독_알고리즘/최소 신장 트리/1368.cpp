#include <bits/stdc++.h>
using namespace std;

int n, p[302];
vector<tuple<int, int, int>> edge;

int find(int x) {
	if (p[x] == x) return x;
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

	cin >> n;
	for (int i = 1, w; i <= n; i++) {
		p[i] = i;
		cin >> w;
		edge.push_back({w, i, n + 1});
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1, c; j <= n; j++) {
			cin >> c;
			if (i >= j) continue;
			edge.push_back({c, i, j});
		}
	}

	int cnt = 0, ans = 0;
	sort(edge.begin(), edge.end());
	for (int i = 0, c, a, b; i < edge.size(); i++) {
		tie(c, a, b) = edge[i];
		if (find(a) == find(b)) continue;
		merge(a, b);
		ans += c;
		cnt++;
		if (cnt == n) break;
	}
	cout << ans;
}