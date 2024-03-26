#include <bits/stdc++.h>
using namespace std;

const int INF = 1000;
int n, m;
int w[251][251];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		fill(w[i], w[i] + n + 1, INF);
		w[i][i] = 0;
	}
	while (m--) {
		int u, v, b;
		cin >> u >> v >> b;
		w[u][v] = min(w[u][v], 0);
		w[v][u] = min(w[v][u], 1 - b);
	}
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				w[i][j] = min(w[i][j], w[i][k] + w[k][j]);
			}
		}
	}

	int k;
	cin >> k;
	while (k--) {
		int s, e;
		cin >> s >> e;
		cout << w[s][e] << "\n";
	}
}