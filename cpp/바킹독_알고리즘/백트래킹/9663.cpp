#include <bits/stdc++.h>
using namespace std;

int n, cnt;

bool is_used[3][30];

void func(int cur) {
	if (cur == n) {
		cnt++;
		return;
	}

	for (int i = 0; i < n; i++) {
		if (is_used[0][i] || is_used[1][cur + i] || is_used[2][cur - i + n - 1]) continue;
		is_used[0][i] = true;
		is_used[1][cur + i] = true;
		is_used[2][cur - i + n - 1] = true;

		func(cur + 1);

		is_used[0][i] = false;
		is_used[1][cur + i] = false;
		is_used[2][cur - i + n - 1] = false;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	func(0);
	cout << cnt;
}