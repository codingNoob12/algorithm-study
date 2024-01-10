#include <bits/stdc++.h>
using namespace std;

int N;
char ans[2200][2200];

void func(int n, int r, int c) {
	if (n == 3) {
		for (int i = r; i < r + n; i++) {
			for (int j = c; j < c + n; j++) {
				if (i % 3 == 1 && j % 3 == 1) continue;
				else ans[i][j] = '*';
			}
		}
		return;
	}

	n /= 3;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (i == 1 && j == 1) continue;
			func(n, i * n + r, j * n + c);
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	for (int i = 0; i < 2200; i++) {
		for (int j = 0; j < 2200; j++) ans[i][j] = ' ';
	}

	cin >> N;
	func(N, 0, 0);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) cout << ans[i][j];
		cout << "\n";
	}
}