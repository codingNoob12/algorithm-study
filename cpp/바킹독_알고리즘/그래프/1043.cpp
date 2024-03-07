#include <bits/stdc++.h>
using namespace std;

int n, m, k;
set<int> adj[51]; // 이야기를 공유할 수 있는 관계를 그래프로 표현.
vector<int> fact, party[50];
bool vis[51];

void bfs() { // 이야기 공유가능한 관계를 bfs로 탐색
	queue<int> q;

	for (int f : fact) {
		q.push(f);
		vis[f] = 1;
	}

	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		for (int nxt : adj[cur]) {
			if (vis[nxt]) continue;
			q.push(nxt);
			vis[nxt] = 1;
		}
	}
}

bool exaggerate(int i) { // 파티에서 과장해서 이야기 할 수 있는지 확인
	for (int p : party[i]) {
		if (vis[p]) return 0;
	}
	return 1;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> k;
	while (k--) {
		int x;
		cin >> x;
		fact.push_back(x);
	}

	for (int i = 0; i < m; i++) {
		cin >> k;
		for (int j = 0; j < k; j++) {
			int x;
			cin >> x;
			party[i].push_back(x);
		}

		for (int idx1 = 0; idx1 < k; idx1++) {
			for (int idx2 = 0; idx2 < k; idx2++) {
				if (idx1 == idx2) continue;
				int u = party[i][idx1], v = party[i][idx2];
				adj[u].insert(v);
				adj[v].insert(u);
			}
		}
	}

	bfs();

	int ans = 0;
	for (int i = 0; i < m; i++) {
		if (exaggerate(i)) ans++;
	}
	cout << ans;
}