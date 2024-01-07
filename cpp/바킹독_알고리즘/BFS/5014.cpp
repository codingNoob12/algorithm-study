#include <bits/stdc++.h>
using namespace std;

int f, s, g, u, d;
queue<int> Q;
int visited[1000001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	fill(visited, visited + 1000001, -1);

	// 입력
	cin >> f >> s >> g >> u >> d;

	// bfs + visited => couting
	Q.push(s);
	visited[s] = 0;

	while (!Q.empty() && Q.front() != g) {
		int x = Q.front();
		Q.pop();

		if (x + u <= f && visited[x + u] == -1) {
			Q.push(x + u);
			visited[x + u] = visited[x] + 1;
		}
		if (x - d > 0 && visited[x - d] == -1) {
			Q.push(x - d);
			visited[x - d] = visited[x] + 1;
		}
	}

	if (!Q.empty()) cout << visited[g];
	else cout << "use the stairs";
}