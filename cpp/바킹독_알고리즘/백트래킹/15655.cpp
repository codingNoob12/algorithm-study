#include <bits/stdc++.h>
using namespace std;

int n, m;
int num[10];
int idx[10];
bool is_used[10];

void func(int k) {
	if (k == m) {
		for (int i = 0; i < m; i++) cout << num[idx[i]] << " ";
		cout << "\n";
		return;
	}

	int st = 0;
	if (k != 0) st = idx[k - 1];
	for (int i = st; i < n; i++) {
		if (is_used[i]) continue;
		idx[k] = i;
		is_used[i] = true;
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