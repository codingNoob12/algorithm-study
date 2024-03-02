#include <bits/stdc++.h>
using namespace std;

string s;
unordered_set<string> us;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> s;
	for (int i = 0; i < s.length(); i++) {
		for (int j = 1; i + j <= s.length(); j++) us.insert(s.substr(i, j));
	}
	cout << us.size();
}