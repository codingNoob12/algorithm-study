#include <bits/stdc++.h>
using namespace std;

int n, q, cur = 1;
set<int> att;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		bool isAtt;
		cin >> isAtt;
		if (isAtt) att.insert(i);
	}

	while (q--) {
		int c;
		cin >> c;
		if (c == 1) {
			int i;
			cin >> i;
			if (att.find(i) != att.end()) att.erase(i);
			else att.insert(i);
		} else if (c == 2) {
			int x;
			cin >> x;
			cur = (cur + x - 1) % n + 1;
		} else {
			if (att.empty()) {
				cout << -1 << "\n";
				continue;
			}
			auto it = att.lower_bound(cur);
			if (it == att.end()) it = att.begin();
			int dist = *it - cur;
			if (dist < 0) dist += n;
			cout << dist << "\n";
		}
	}
}