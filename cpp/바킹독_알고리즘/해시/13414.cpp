#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;

int k, l;
unordered_map<string, int> m;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> k >> l;
	for (int i = 1; i <= l; i++) {
		string id;
		cin >> id;
		m[id] = i;
	}

	vector<pair<string, int>> v(m.begin(), m.end());
	sort(v.begin(), v.end(), [](const pair<string, int> &a, const pair<string, int> &b) {
	  return a.Y < b.Y;
	});

	int sz = min(k, (int)v.size());
	for (int i = 0; i < sz; i++) cout << v[i].X << "\n";
}