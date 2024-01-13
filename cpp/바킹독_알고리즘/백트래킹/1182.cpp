#include <bits/stdc++.h>
using namespace std;

int n, s, cnt;
int arr[20];
int idx[20];
bool is_used[20];

void func(int k, int r) {
	if (k == r) {
		int sum = 0;
		for (int i = 0; i < r; i++) sum += arr[idx[i]];
		if (sum == s) cnt++;
		return;
	}

	for (int i = 0; i < n; i++) {
		if (is_used[i]) continue;
		bool is_continue = false;
		for (int j = 0; j < k; j++) {
			if (idx[j] > i) {
				is_continue = true;
				break;
			}
		}
		if (is_continue) continue;
		idx[k] = i;
		is_used[i] = true;
		func(k + 1, r);
		is_used[i] = false;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> s;
	for (int i = 0; i < n; i++) cin >> arr[i];

	for (int i = 1; i <= n; i++) func(0, i);
	cout << cnt;
}