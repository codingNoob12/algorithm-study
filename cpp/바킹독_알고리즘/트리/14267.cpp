#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> c[100'001];
int p[100'001];

void dfs(int cur) {
	for (int nxt : c[cur]) {
		p[nxt] += p[cur];
		dfs(nxt);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 1, t; i <= n; i++) {
		cin >> t;
		if (t == -1) continue;
		c[t].push_back(i);
	}

	while (m--) {
		int e, w;
		cin >> e >> w;
		p[e] += w;
	}
	dfs(1);
	for (int i = 1; i <= n; i++) cout << p[i] << " ";
}