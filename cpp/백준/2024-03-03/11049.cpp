#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;

int n, r, c;
int d[501][501];
pair<int, int> m[501];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++) cin >> m[i].X >> m[i].Y;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; i + j <= n; j++) {
			d[j][i + j] = INT_MAX;
			for (int k = j; k < i + j; k++) {
				d[j][i + j] = min(d[j][i + j],
								  d[j][k] + d[k + 1][i + j] + m[j].X * m[k].Y * m[i + j].Y);
			}
		}
	}

	cout << d[1][n];
}