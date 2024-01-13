#include <bits/stdc++.h>
using namespace std;

int n, m;
int num[10];
int arr[10];
bool is_used[10];

void func(int k) {
	if (k == m) {
		for (int i = 0; i < m; i++) cout << arr[i] << " ";
		cout << "\n";
		return;
	}

	int tmp = 0;
	for (int i = 0; i < n; i++) {
		if (is_used[i] || tmp == num[i]) continue;
		is_used[i] = true;
		arr[k] = tmp = num[i];
		func(k + 1);
		is_used[i] = false;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> num[i];
	sort(num, num + n);
	func(0);
}