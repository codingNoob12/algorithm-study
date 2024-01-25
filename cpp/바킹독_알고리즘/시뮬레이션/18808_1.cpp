#include <bits/stdc++.h>
using namespace std;

int n, m, k;
int board[40][40];
int r, c;
int sticker[10][10];

bool pasteable(int x, int y) {
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (sticker[i][j] && board[x + i][y + j]) return 0;
		}
	}
	return 1;
}

void paste(int x, int y) {
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (sticker[i][j]) board[x + i][y + j] = 1;
		}
	}
}

void rotate() {
	int tmp[10][10] = {};
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) tmp[i][j] = sticker[i][j];
	}

	for (int i = 0; i < c; i++) {
		for (int j = 0; j < r; j++) sticker[i][j] = tmp[r - 1 - j][i];
	}
	swap(r, c);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> k;
	while (k--) {
		cin >> r >> c;
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) cin >> sticker[i][j];
		}

		for (int rot = 0; rot < 4; rot++) {
			bool is_pasted = 0;
			for (int x = 0; x <= n - r; x++) {
				for (int y = 0; y <= m - c; y++) {
					if (pasteable(x, y)) {
						paste(x, y);
						is_pasted = 1;
						break;
					}
				}
				if (is_pasted) break;
			}
			if (is_pasted) break;
			rotate();
		}
	}

	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) ans += board[i][j];
	}
	cout << ans;
}