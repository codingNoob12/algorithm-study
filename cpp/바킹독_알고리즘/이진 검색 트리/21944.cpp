#include <bits/stdc++.h>
using namespace std;

int n, m;
set<pair<int, int>> group[101]; // {레벨, 번호}
set<int> level[101];
map<int, pair<int, int>> problem; // 문제 번호 -> {레벨, 그룹}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		int p, l, g;
		cin >> p >> l >> g;
		group[g].insert({l, p});
		level[l].insert(p);
		problem[p] = {l, g};
	}

	cin >> m;
	while (m--) {
		string c;
		cin >> c;
		if (c == "recommend") {
			int g, x;
			cin >> g >> x;
			if (x > 0) cout << prev(group[g].end())->second << "\n";
			else cout << group[g].begin()->second << "\n";
		} else if (c == "recommend2") {
			int x;
			cin >> x;
			if (x > 0) {
				for (int i = 100; i > 0; i--) {
					if (level[i].empty()) continue;
					cout << *prev(level[i].end()) << "\n";
					break;
				}
			} else {
				for (int i = 1; i <= 100; i++) {
					if (level[i].empty()) continue;
					cout << *level[i].begin() << "\n";
					break;
				}
			}
		} else if (c == "recommend3") {
			int x, l;
			bool isExist = 0;
			cin >> x >> l;
			if (x > 0) {
				for (int i = l; i <= 100; i++) {
					if (level[i].empty()) continue;
					cout << *level[i].begin() << "\n";
					isExist = 1;
					break;
				}
			} else {
				for (int i = l - 1; i > 0; i--) {
					if (level[i].empty()) continue;
					cout << *prev(level[i].end()) << "\n";
					isExist = 1;
					break;
				}
			}
			if (!isExist) cout << -1 << "\n";
		} else if (c == "add") {
			int p, l, g;
			cin >> p >> l >> g;
			group[g].insert({l, p});
			level[l].insert(p);
			problem[p] = {l, g};
		} else {
			int p, l, g;
			cin >> p;
			tie(l, g) = problem[p];
			level[l].erase(p);
			group[g].erase({l, p});
		}
	}
}