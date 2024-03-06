#include <bits/stdc++.h>
using namespace std;

priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq; // {abs(x), x}
int n, x;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	while (n--) {
		cin >> x;
		if (x) pq.push({abs(x), x});
		else {
			if (pq.empty()) cout << 0 << "\n";
			else {
				cout << pq.top().second << "\n";
				pq.pop();
			}
		}
	}
}