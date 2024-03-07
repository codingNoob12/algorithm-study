#include <bits/stdc++.h>
using namespace std;

int n;
int adj[101][101];
bool vis[101][101];

void bfs() {
	for (int i = 1; i <= n; i++) {
		queue<int> q;
		q.push(i);

		while (!q.empty()) {
			int cur = q.front();
			q.pop();

			for (int nxt = 1; nxt <= n; nxt++) {
				if (cur == nxt || !adj[cur][nxt]) continue;
				if (vis[i][nxt]) continue;
				q.push(nxt);
				vis[i][nxt] = 1;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) cin >> adj[i][j];
	}

	bfs();
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) cout << vis[i][j] << " ";
		cout << "\n";
	}
}