#include <bits/stdc++.h>
using namespace std;

int n, m;
int num[10];
int idx[10];

void func(int k) {
	if (k == m) {
		for (int i = 0; i < k; i++) cout << num[idx[i]] << " ";
		cout << "\n";
		return;
	}

	for (int i = 0; i < n; i++) {
		idx[k] = i;
		func(k + 1);
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