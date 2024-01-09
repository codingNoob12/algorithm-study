#include <bits/stdc++.h>
using namespace std;

int N;
int arr[2200][2200];
int cnt_arr[3];

bool check(int n, int r, int c) {
	for (int i = r; i < r + n; i++) {
		for (int j = c; j < c + n; j++) {
			if (arr[i][j] != arr[r][c]) return false;
		}
	}
	return true;
}

void func(int n, int r, int c) {
	if (check(n, r, c)) {
		cnt_arr[arr[r][c] + 1]++;
		return;
	}
	n /= 3;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) func(n, n * i + r, n * j + c);
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

	for (int i = 0; i < 3; i++) cout << cnt_arr[i] << "\n";
}