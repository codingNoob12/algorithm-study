#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
int n, m;
int w[101][101], nxt[101][101];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	for (int i = 1; i <= 100; i++) {
		fill(w[i], w[i] + 101, INF);
		w[i][i] = 0;
	}

	cin >> n >> m;
	for (int i = 0, a, b, c; i < m; i++) {
		cin >> a >> b >> c;
		if (w[a][b] > c) {
			w[a][b] = c;
			nxt[a][b] = b;
		}
	}

	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (w[i][j] > w[i][k] + w[k][j]) {
					w[i][j] = w[i][k] + w[k][j];
					nxt[i][j] = nxt[i][k];
				}
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (w[i][j] == INF) cout << 0 << " ";
			else cout << w[i][j] << " ";
		}
		cout << "\n";
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (w[i][j] == 0 || w[i][j] == INF) {
				cout << 0 << "\n";
				continue;
			}
			vector<int> v;
			int s = i;
			while (s != j) {
				v.push_back(s);
				s = nxt[s][j];
			}
			if (!v.empty()) v.push_back(s);
			cout << v.size() << " ";
			for (int x : v) cout << x << " ";
			cout << "\n";
		}
	}
}