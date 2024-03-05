#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;

int n, k;
pair<int, int> jewels[300'000]; // {V, M}
multiset<int> bags;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;
	for (int i = 0; i < n; i++) cin >> jewels[i].Y >> jewels[i].X;
	sort(jewels, jewels + n);

	for (int i = 0; i < k; i++) {
		int c;
		cin >> c;
		bags.insert(c);
	}

	long long ans = 0;
	for (int i = n - 1; i >= 0; i--) {
		int m, v;
		tie(v, m) = jewels[i];
		auto it = bags.lower_bound(m);
		if (it == bags.end()) continue;
		ans += v;
		bags.erase(it);
	}
	cout << ans;
}