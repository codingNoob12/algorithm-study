#include <bits/stdc++.h>
using namespace std;

int n, m;
unordered_map<string, int> um;
vector<string> v;
string s;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> s;
		um[s] = i + 1;
		v.push_back(s);
	}

	for (int i = 0; i < m; i++) {
		cin >> s;
		if (um.find(s) != um.end()) cout << um[s] << "\n";
		else cout << v[stoi(s) - 1] << "\n";
	}
}