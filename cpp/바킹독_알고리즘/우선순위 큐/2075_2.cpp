#include <bits/stdc++.h>
using namespace std;

int n;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	vector<int> a(n * n);
	for (int i = 0, x; i < n * n; i++) cin >> a[i];
	sort(a.begin(), a.end(), greater<>());
	cout << a[n - 1];
}