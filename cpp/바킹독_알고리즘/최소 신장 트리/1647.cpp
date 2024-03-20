#include <bits/stdc++.h>
using namespace std;

int n, m;
tuple<int, int, int> edge[1'000'000];
vector<int> p(100'001, -1);
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

	cin >> n >> m;
	for (int i = 0, a, b, c; i < m; i++) {
		cin >> a >> b >> c;
		edge[i] = {c, a, b};
	}

	sort(edge, edge + m);
	for (int i = 0, a, b, c, cnt = n; i < m; i++) {
		tie(c, a, b) = edge[i];
		if (cnt == 2) break;
		if (find(a) == find(b)) continue;
		merge(a, b);
		ans += c;
		cnt--;
	}
	cout << ans;
}