#include <bits/stdc++.h>
using namespace std;

int n, m, k, r, c;
int board[40][40];

vector<vector<int>> flip(vector<vector<int>> arr) {
	vector<vector<int>> ret;
	for (int j = 0; j < arr[0].size(); j++) {
		vector<int> row;
		for (int i = arr.size() - 1; i >= 0; i--) row.push_back(arr[i][j]);
		ret.push_back(row);
	}
	return ret;
}

bool is_attachable(int x, int y, vector<vector<int>> arr) {
	for (int i = 0; i < arr.size(); i++) {
		for (int j = 0; j < arr[i].size(); j++) {
			if (x + i >= n || y + j >= m) return 0;
			if (arr[i][j] && board[x + i][y + j]) return 0;
		}
	}
	return 1;
}

void attach(int x, int y, vector<vector<int>> arr) {
	for (int i = 0; i < arr.size(); i++) {
		for (int j = 0; j < arr[i].size(); j++) {
			if (arr[i][j]) board[x + i][y + j] = arr[i][j];
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> k;
	while (k--) {
		cin >> r >> c;
		vector<vector<int>> sticker(r, vector<int>(c, 0));
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) cin >> sticker[i][j];
		}

		bool is_attached = 0;
		int cnt = 0;
		while (!is_attached && cnt < 4) {
			for (int i = 0; i < n; i++) {
				if (i + sticker.size() > n) break;
				for (int j = 0; j < m; j++) {
					if (j + sticker[0].size() > m) break;
					if (is_attachable(i, j, sticker)) {
						attach(i, j, sticker);
						is_attached = 1;
					}
					if (is_attached) break;
				}
				if (is_attached) break;
			}
			sticker = flip(sticker);
			cnt++;
		}
	}

	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) cnt += board[i][j] != 0;
	}
	cout << cnt;
}
/*
 * 입력
 * 세로크기(N), 가로길이(M), 스티커 개수(K)
 * 스티커의 행(R)과 열(C)
 * 스티커 모양
 *
 * 스티커가와 노트북의 크기가 주어졌을 때, 스티커를 붙여보자
 * 스티커를 그대로 붙일 수 있으면, 그대로 붙인다.
 * 그렇지 못하면, 회전시켜 붙일 수 있으면 회전시켜 붙인다. (90도, 180도, 270도)
 * 그래도 못붙히면 버린다.
 *
 * 단, 스티커를 붙일 수 있는 공간이 여러 군데면, 좌상단부터 붙여간다.
 *
 * 스티커가 붙은 칸수를 출력한다.
 *
 * //==아이디어==//
 * N과 M이 40이하, K가 100이하이므로 모든 칸에서 스티커를 붙일 수 있는지 여부를 확인하고
 * 붙여나가도 될 것 같다.
 *
 * 시간복잡도가 O(NMK)이므로 160,000이기 때문이다.
 */