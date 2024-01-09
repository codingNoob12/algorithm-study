#include <bits/stdc++.h>
using namespace std;

int N;
int arr[200][200];
int cnt[2];

bool check(int n, int r, int c) {
	for (int i = r; i < r + n; i++) {
		for (int j = c; j < c + n; j++) {
			if (arr[r][c] != arr[i][j]) return false;
		}
	}
	return true;
}

void func(int n, int r, int c) {
	if (check(n, r, c)) {
		cnt[arr[r][c]]++;
		return;
	}
	n /= 2;
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) func(n, i * n + r, j * n + c);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) cin >> arr[i][j];
	}

	func(N, 0, 0);

	for (auto e : cnt) cout << e << "\n";
}