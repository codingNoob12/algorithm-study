#include <bits/stdc++.h>
using namespace std;

int n, m;
int nums[10];
int arr[10];
bool is_used[10];

void func(int k) {
	if (k == m) {
		for (int i = 0; i < m; i++) cout << arr[i] << " ";
		cout << "\n";
		return;
	}

	for (int i = 0; i < n; i++) {
		if (is_used[i]) continue;
		arr[k] = nums[i];
		is_used[i] = true;
		func(k + 1);
		is_used[i] = false;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> nums[i];
	sort(nums, nums + n);
	func(0);
}