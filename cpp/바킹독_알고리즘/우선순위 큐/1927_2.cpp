#include <bits/stdc++.h>
using namespace std;

priority_queue<int, vector<int>, greater<>> pq;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, x;
	cin >> n;
	while (n--) {
		cin >> x;
		if (!x) {
			if (pq.empty()) cout << 0 << "\n";
			else {
				cout << pq.top() << "\n";
				pq.pop();
			}
		} else pq.push(x);
	}
}