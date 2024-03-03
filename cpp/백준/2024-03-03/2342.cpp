#include <bits/stdc++.h>
using namespace std;

int x;
int d[100'001][5][5];

int force(int i, int j) {
	if (i == 0) return 2;
	if (i == j) return 1;
	if (abs(i - j) == 2) return 4;
	return 3;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int i = 1;
	cin >> x;
	if (!x) {
		cout << 0;
		return 0;
	}

	d[i][0][x] = 2, d[i][x][0] = 2;
	while (1) {
		cin >> x;
		if (!x) break;
		i++;
		for (int j = 0; j < 5; j++) {
			for (int k = 0; k < 5; k++) {
				if (!d[i - 1][j][k]) continue;

				int f = force(k, x);
				if (d[i][j][x]) d[i][j][x] = min(d[i - 1][j][k] + f, d[i][j][x]);
				else d[i][j][x] = d[i - 1][j][k] + f;

				f = force(j, x);
				if (d[i][x][k]) d[i][x][k] = min(d[i - 1][j][k] + f, d[i][x][k]);
				else d[i][x][k] = d[i - 1][j][k] + f;
			}
		}
	}

	int ans = 0x7f7f7f7f;
	for (int j = 0; j < 5; j++) {
		for (int k = 0; k < 5; k++) {
			if (!d[i][j][k]) continue;
			ans = min(ans, d[i][j][k]);
		}
	}

	cout << ans;
}