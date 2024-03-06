#include <bits/stdc++.h>
using namespace std;

int n, x;
priority_queue<int> pq;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	while (n--) {
		cin >> x;
		if (x) pq.push(x);
		else {
			if (pq.empty()) cout << 0 << "\n";
			else {
				cout << pq.top() << "\n";
				pq.pop();
			}
		}
	}
}