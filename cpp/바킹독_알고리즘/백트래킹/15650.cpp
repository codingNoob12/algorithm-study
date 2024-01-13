#include <bits/stdc++.h>
using namespace std;

int n, m;
int arr[10];
bool is_used[10];

void func(int k) {
	if (k == m) {
		for (int i = 0; i < m; i++)
			cout << arr[i] << ' ';
		cout << '\n';
		return;
	}
	int st = 1;
	if (k != 0) st = arr[k - 1] + 1;
	for (int i = st; i <= n; i++) {
		if (is_used[i]) continue;
		arr[k] = i;
		is_used[i] = true;
		func(k + 1);
		is_used[i] = false;
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	func(0);
}