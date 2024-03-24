#include <bits/stdc++.h>
using namespace std;

int n, m, cnt;
string s, target = "I";

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> s;
	for (int i = 0; i < n; i++) target += "OI";

	for (int i = 0; i <= m - (2 * n + 1); i++) {
		string sub = s.substr(i, 2 * n + 1);
		if (sub == target) cnt++;
	}
	cout << cnt;
}