#include <bits/stdc++.h>
using namespace std;

int tc;
int n, m;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> tc;
	while (tc--) {
		cin >> n >> m;
		for (int i = 0, a, b; i < m; i++) cin >> a >> b;
		cout << n - 1 << "\n";
	}
}