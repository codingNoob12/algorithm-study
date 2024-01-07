#include <bits/stdc++.h>
using namespace std;

int n, k;
queue<int> Q;
int visited[100001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	fill(visited, visited + 100001, -1);

	cin >> n >> k;

	Q.push(n);
	visited[n] = 0;

	while (!Q.empty() && Q.front() != k) {
		int x = Q.front();
		Q.pop();

		if (x - 1 >= 0 && visited[x - 1] == -1) {
			Q.push(x - 1);
			visited[x - 1] = visited[x] + 1;
		}
		if (x + 1 <= 100000 && visited[x + 1] == -1) {
			Q.push(x + 1);
			visited[x + 1] = visited[x] + 1;
		}
		if (2 * x <= 100000 && visited[2 * x] == -1) {
			Q.push(2 * x);
			visited[2 * x] = visited[x] + 1;
		}
	}

	cout << visited[k];
}