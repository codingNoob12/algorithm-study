#include <bits/stdc++.h>
using namespace std;

const int INF = 1e7;
int v, e, ans = INF;
int w[401][401];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	// 입력
	cin >> v >> e;
	for (int i = 1; i <= v; i++) {
		fill(w[i], w[i] + v + 1, INF);
		w[i][i] = 0;
	}
	for (int i = 0, a, b, c; i < e; i++) {
		cin >> a >> b >> c;
		w[a][b] = min(w[a][b], c);
	}

	// 플로이드 => 최단 경로
	for (int k = 1; k <= v; k++) {
		for (int i = 1; i <= v; i++) {
			for (int j = 1; j <= v; j++) {
				w[i][j] = min(w[i][j], w[i][k] + w[k][j]);
			}
		}
	}

	// 최소인 왕복 거리 구하기
	for (int i = 1; i <= v; i++) {
		for (int j = 1; j <= v; j++) {
			if (i == j || w[i][j] + w[j][i] > INF) continue;
			ans = min(ans, w[i][j] + w[j][i]);
		}
	}

	if (ans == INF) cout << -1;
	else cout << ans;
}