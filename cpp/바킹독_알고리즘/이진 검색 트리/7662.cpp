#include <bits/stdc++.h>
using namespace std;

int tc;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> tc;
	while (tc--) {
		int k, n;
		char c;
		multiset<int> s;

		cin >> k;
		for (int i = 0; i < k; i++) {
			cin >> c >> n;
			if (c == 'I') s.insert(n);
			else if (s.empty()) continue;
			else if (n < 0) s.erase(s.begin());
			else s.erase(prev(s.end()));
		}

		if (s.empty()) cout << "EMPTY" << "\n";
		else cout << *prev(s.end()) << " " << *s.begin() << "\n";
	}
}