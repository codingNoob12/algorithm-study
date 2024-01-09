#include <bits/stdc++.h>
using namespace std;

int cnt = 0;

int func(int n, int r, int c) {
	if (n == 1) return 0;
	n /= 2;
	int squares = n * n, k;
	if (r < n) {
		if (c < n) k = 0;
		else k = 1;
	} else {
		if (c < n) k = 2;
		else k = 3;
	}
	return k * squares + func(n, r % n, c % n);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, r, c;
	cin >> n >> r >> c;
	cout << func(1 << n, r, c);
}