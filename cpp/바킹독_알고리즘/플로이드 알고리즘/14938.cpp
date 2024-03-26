#include <bits/stdc++.h>
using namespace std;

const int INF = 100;
int n, m, r;
int w[101][101], item[101], ans;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> r;
	for (int i = 1; i <= n; i++) {
		fill(w[i], w[i] + n + 1, INF);
		w[i][i] = 0;
	}
	for (int i = 1; i <= n; i++) cin >> item[i];
	for (int i = 0, a, b, l; i < r; i++) {
		cin >> a >> b >> l;
		w[a][b] = min(w[a][b], l);
		w[b][a] = min(w[b][a], l);
	}

	// 플로이드로 최단 경로 구하기
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				w[i][j] = min(w[i][j], w[i][k] + w[k][j]);
			}
		}
	}

	// 각 지점에서 최단 경로가 m이하인 지점의 아이템 합 구하기
	for (int i = 1; i <= n; i++) {
		int tot = 0;
		for (int j = 1; j <= n; j++) {
			if (w[i][j] <= m) tot += item[j];
		}
		ans = max(ans, tot);
	}
	cout << ans;
}