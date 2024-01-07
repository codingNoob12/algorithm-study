#include <bits/stdc++.h>
using namespace std;

int t;
int selections[100001];
int status[100001];

const int NOT_VISITED = 0;
const int IN_CYCLE = -1;

void check(int x) {
	int cur = x;
	while (true) {
		status[cur] = x;
		cur = selections[cur];

		if (status[cur] == x) {
			while (status[cur] != IN_CYCLE) {
				status[cur] = IN_CYCLE;
				cur = selections[cur];
			}
			return;
		} else if (status[cur] != NOT_VISITED) return;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		fill(status + 1, status + n + 1, 0);

		for (int i = 1; i <= n; i++) cin >> selections[i];

		for (int i = 1; i <= n; i++) {
			if (status[i] == NOT_VISITED) check(i);
		}

		int cnt = 0;
		for (int i = 1; i <= n; i++) {
			if (status[i] != IN_CYCLE) cnt++;
		}

		cout << cnt << "\n";
	}
}