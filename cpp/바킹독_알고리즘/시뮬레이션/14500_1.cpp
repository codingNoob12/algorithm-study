#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;

int n, m, mx;
int board[501][501];
vector<vector<pair<int, int>>> tetro;

bool is_adj(pair<int, int> &a, pair<int, int> &b) {
	if (a.X == b.X) return abs(a.Y - b.Y) == 1;
	if (a.Y == b.Y) return abs(a.X - b.X) == 1;
	return 0;
}

bool is_conn(vector<pair<int, int>> &shape) {
	bool flag = 0;
	for (int i = 0; i < 4; i++) {
		int cnt = 0;
		for (int j = 0; j < 4; j++) {
			if (is_adj(shape[i], shape[j])) cnt++;
		}

		if (cnt == 0) return 0;
		if (cnt >= 2) flag = 1;
	}
	return flag;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) cin >> board[i][j];
	}

	// 4x4에서 가능한 모든 테트로미노를 구하기
	vector<int> brute(16);
	fill(prev(brute.end(), 4), brute.end(), 1);
	do {
		vector<pair<int, int>> shape;
		for (int i = 0; i < brute.size(); i++) {
			if (!brute[i]) continue;
			shape.push_back({i / 4, i % 4});
		}
		if (is_conn(shape)) tetro.push_back(shape);
	} while (next_permutation(brute.begin(), brute.end()));

	for (int i = 0; i <= n - 4; i++) {
		for (int j = 0; j <= m - 4; j++) {
			for (auto t : tetro) {
				int sum = 0;
				for (auto p : t) sum += board[i + p.X][j + p.Y];
				mx = max(mx, sum);
			}
		}
	}
	cout << mx;
}