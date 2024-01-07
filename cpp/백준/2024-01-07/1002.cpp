#include <bits/stdc++.h>
using namespace std;

int T;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> T;
	while (T--) {
		int x1, y1, r1, x2, y2, r2;
		cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;

		double dist = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
		if (dist == 0 && r1 == r2) cout << -1 << "\n";
		else if (dist > r1 + r2 || dist < max(r1, r2) - min(r1, r2)) cout << 0 << "\n";
		else if (dist == r1 + r2 || dist == max(r1, r2) - min(r1, r2)) cout << 1 << "\n";
		else cout << 2 << "\n";
	}
}