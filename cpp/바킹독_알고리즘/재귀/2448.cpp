#include <bits/stdc++.h>
using namespace std;

const int MAX = 1024 * 3 + 2;

int N;
char ans[MAX][MAX * 2 - 1];

void func(int n, int r, int c) {
	if (n == 3) {
		for (int i = r; i < r + n; i++) {
			ans[i][c - i + r] = ans[i][c + i - r] = '*';
			if (i != r + n - 1) continue;
			for (int j = 0; j < 2; j++) ans[i][c - j] = ans[i][c + j] = '*';
		}
		return;
	}
	n /= 2;
	func(n, r, c);
	func(n, r + n, c - n);
	func(n, r + n, c + n);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	for (auto e : ans) fill(e, e + MAX * 2, ' ');

	cin >> N;

	func(N, 0, N - 1);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 2 * N - 1; j++) cout << ans[i][j];
		cout << "\n";
	}
}