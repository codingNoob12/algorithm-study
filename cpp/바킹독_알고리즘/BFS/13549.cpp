#include <bits/stdc++.h>
using namespace std;

int n, k;
int visited[100001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	fill(visited, visited + 100001, -1);

	cin >> n >> k;

	queue<int> q;
	q.push(n);
	visited[n] = 0;

	while (!q.empty()) {
		int x = q.front();
		q.pop();

		if (x == k) {
			cout << visited[x];
			break;
		}

		if (2 * x <= 100000 && visited[2 * x] == -1) {
			q.push(2 * x);
			visited[2 * x] = visited[x];
		}
		if (x - 1 >= 0 && visited[x - 1] == -1) {
			q.push(x - 1);
			visited[x - 1] = visited[x] + 1;
		}
		if (x + 1 <= 100000 & visited[x + 1] == -1) {
			q.push(x + 1);
			visited[x + 1] = visited[x] + 1;
		}
	}
}