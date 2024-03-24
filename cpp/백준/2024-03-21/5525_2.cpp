#include <bits/stdc++.h>
using namespace std;

int n, m, cnt;
string s;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> s;
	int i = 0, j;
	for (; i < m && s[i] != 'I'; i++);
	for (j = i + 1; j < m - 1; j++) {
		if (s[j] == 'O' && s[j + 1] == 'I') {
			if ((++j + 1 - i) / 2 >= n) cnt++;
		} else {
			for (i = j; i < m && s[i] != 'I'; i++);
			j = i;
		}
	}
	cout << cnt;
}
