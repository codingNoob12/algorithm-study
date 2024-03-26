#include <bits/stdc++.h>
using namespace std;

const int INF = 10'000;
int n, m, k;
int w[201][201], t[201], city[201];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	// 입력
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		fill(w[i], w[i] + n + 1, INF);
		w[i][i] = 0;
	}
	for (int i = 0, a, b, c; i < m; i++) {
		cin >> a >> b >> c;
		w[a][b] = min(w[a][b], c);
	}
	cin >> k;
	for (int i = 1; i <= k; i++) cin >> city[i];

	// 플로이드로 이동시간
	for (int v = 1; v <= n; v++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				w[i][j] = min(w[i][j], w[i][v] + w[v][j]);
			}
		}
	}

	// 임의의 도시로의 왕복시간 구하기 (최대값 저장)
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= k; j++) {
			t[i] = max(t[i], w[i][city[j]] + w[city[j]][i]);
		}
	}

	// 왕복시간들 중 최소인 도시 구하기
	int mn = *min_element(t + 1, t + n + 1);
	for (int i = 1; i <= n; i++) {
		if (t[i] == mn) cout << i << " ";
	}
}