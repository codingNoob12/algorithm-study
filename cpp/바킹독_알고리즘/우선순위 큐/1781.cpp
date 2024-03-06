#include <bits/stdc++.h>
using namespace std;

int n, ans;
vector<vector<int>> cnt(200'001);
priority_queue<int> pq;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0, d, c; i < n; i++) {
		cin >> d >> c;
		cnt[d].push_back(c);
	}

	for (int i = n; i > 0; i--) {
		for (int c : cnt[i]) pq.push(c);
		if (pq.empty()) continue;
		ans += pq.top();
		pq.pop();
	}
	cout << ans;
}