#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;
using ll = long long;

int n, m, cnt;
pair<int, int> coord[1001];
vector<int> p(1001, -1);
vector<tuple<ll, int, int>> edge; // {비용, 정점1, 정점2}
double ans;

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
	cout << fixed;
	cout.precision(2);

	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> coord[i].X >> coord[i].Y;
	for (int i = 0, x, y; i < m; i++) {
		cin >> x >> y;
		if (find(x) == find(y)) continue;
		merge(x, y);
		cnt++;
	}

	ll square;
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			ll dx = coord[i].X - coord[j].X, dy = coord[i].Y - coord[j].Y;
			ll square = dx * dx + dy * dy;
			edge.push_back({square, i, j});
		}
	}

	sort(edge.begin(), edge.end());

	for (int i = 0; i < edge.size(); i++) {
		int x, y;
		tie(square, x, y) = edge[i];
		if (find(x) == find(y)) continue;
		merge(x, y);
		ans += sqrt(square);
		cnt++;
		if (cnt == n - 1) break;
	}
	cout << ans;
}