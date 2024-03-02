#include <bits/stdc++.h>
using namespace std;

int tc;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> tc;
	while (tc--) {
		unordered_map<string, int> um;
		int n;
		string name, kind;

		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> name >> kind;
			um[kind]++;
		}

		int ans = 1;
		for (auto e : um) ans *= (e.second + 1);
		cout << ans - 1 << "\n";
	}
}