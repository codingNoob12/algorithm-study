#include <bits/stdc++.h>
using namespace std;

int N, M, tot;
int m[101], c[101], d[101][10001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;
	for (int i = 1; i <= N; i++) cin >> m[i];
	for (int i = 1; i <= N; i++) {
		cin >> c[i];
		tot += c[i];
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 0; j <= tot; j++) {
			if (j - c[i] >= 0) d[i][j] = max(d[i - 1][j], d[i - 1][j - c[i]] + m[i]);
			else d[i][j] = d[i - 1][j];
		}
	}

	for (int i = 0; i <= tot; i++) {
		if (d[N][i] >= M) {
			cout << i;
			break;
		}
	}
}