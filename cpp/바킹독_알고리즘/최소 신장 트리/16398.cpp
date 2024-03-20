#include <bits/stdc++.h>
using namespace std;

int n, cnt;
vector<tuple<int, int, int>> edge;
vector<int> p(1001, -1);
long long ans;

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

	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1, c; j <= n; j++) {
			cin >> c;
			if (i >= j) continue;
			edge.push_back({c, i, j});
		}
	}
	sort(edge.begin(), edge.end());
	for (auto e : edge) {
		int c, a, b;
		tie(c, a, b) = e;
		if (find(a) == find(b)) continue;
		merge(a, b);
		ans += c;
		cnt++;
		if (cnt == n - 1) break;
	}
	cout << ans;
}