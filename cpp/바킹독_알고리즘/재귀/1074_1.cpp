#include <bits/stdc++.h>
using namespace std;

int func(int n, int r, int c) {
	if (n == 0) return 0;
	int half = 1 << (n - 1), k;
	if (r < half) {
		if (c < half) k = 0;
		else k = 1;
	} else {
		if (c < half) k = 2;
		else k = 3;
	}
	return k * half * half + func(n - 1, r % half, c % half);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, r, c;
	cin >> n >> r >> c;
	cout << func(n, r, c);
}