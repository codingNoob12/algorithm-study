#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
int n, m;
int d[101][101];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	for (int i = 0; i < 101; i++) {
		fill(d[i], d[i] + 101, INF);
		d[i][i] = 0;
	}

	cin >> n >> m;
	for (int i = 0, a, b, c; i < m; i++) {
		cin >> a >> b >> c;
		d[a][b] = min(d[a][b], c);
	}

	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (d[i][j] == INF) cout << 0 << " ";
			else cout << d[i][j] << " ";
		}
		cout << "\n";
	}
}