#include <bits/stdc++.h>
using namespace std;

int n;
priority_queue<int, vector<int>, greater<>> pq;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0, x; i < n * n; i++) {
		cin >> x;
		pq.push(x);
		while (pq.size() > n) pq.pop();
	}

	cout << pq.top();
}