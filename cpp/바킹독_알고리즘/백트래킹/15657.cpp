#include <bits/stdc++.h>
using namespace std;

int n, m;
int arr[10];
int idx[10];

void func(int k) {
	if (k == m) {
		for (int i = 0; i < m; i++) cout << arr[idx[i]] << " ";
		cout << "\n";
		return;
	}

	int st = 0;
	if (k != 0) st = idx[k - 1];
	for (int i = st; i < n; i++) {
		idx[k] = i;
		func(k + 1);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> arr[i];
	sort(arr, arr + n);
	func(0);
}