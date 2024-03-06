#include <bits/stdc++.h>
using namespace std;

int n, x;
priority_queue<int> mx;
priority_queue<int, vector<int>, greater<>> mn;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> x;
		if (mn.empty() || mn.top() < x) mn.push(x);
		else mx.push(x);

		if (i % 2) {
			while (mx.size() < mn.size() + 1) {
				mx.push(mn.top());
				mn.pop();
			}
			while (mx.size() > mn.size() + 1) {
				mn.push(mx.top());
				mx.pop();
			}
		} else {
			while (mx.size() < mn.size() + 1) {
				mx.push(mn.top());
				mn.pop();
			}
			while (mx.size() > mn.size() + 1) {
				mn.push(mx.top());
				mx.pop();
			}
		}

		cout << mx.top() << "\n";
	}
}