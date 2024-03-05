#include <bits/stdc++.h>
using namespace std;

int n, m;
set<int> problems[101];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		int p, l;
		cin >> p >> l;
		problems[l].insert(p);
	}

	cin >> m;
	while (m--) {
		string cmd;
		cin >> cmd;

		if (cmd == "recommend") {
			int x;
			cin >> x;
			if (x < 0) {
				for (int i = 1; i <= 100; i++) {
					if (!problems[i].empty()) {
						cout << *problems[i].begin() << "\n";
						break;
					}
				}
			} else {
				for (int i = 100; i >= 1; i--) {
					if (!problems[i].empty()) {
						cout << *prev(problems[i].end()) << "\n";
						break;
					}
				}
			}
		} else if (cmd == "add") {
			int p, l;
			cin >> p >> l;
			problems[l].insert(p);
		} else {
			int p;
			cin >> p;
			for (int i = 1; i <= 100; i++) problems[i].erase(p);
		}
	}
}