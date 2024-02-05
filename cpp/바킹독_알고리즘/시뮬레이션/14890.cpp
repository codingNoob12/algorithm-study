#include <bits/stdc++.h>
using namespace std;

int n, l;
int board[100][100];

bool isPath(vector<int> &heights) {
	int height = heights[0];
	vector<bool> slope(n, 0);
	for (int i = 1; i < heights.size(); i++) {
		if (height == heights[i]) continue;
		if (abs(heights[i] - height) > 1) return 0;

		// 경사로를 다 놓지 못하는 경우 false를 리턴하고 종료.
		// 함수가 종료되지 않았다는 것은 경사로 설치가 완료된 것!
		if (height > heights[i]) {
			for (int j = 0; j < l; j++) {
				if (slope[i + j] || i + j >= heights.size()) return 0;
				if (heights[i] != heights[i + j]) return 0;
				slope[i + j] = 1;
			}
		} else {
			for (int j = 0; j < l; j++) {
				if (slope[i - 1 - j] || i - 1 - j < 0) return 0;
				if (heights[i - 1] != heights[i - 1 - j]) return 0;
				slope[i - 1 - j] = 1;
			}
		}
		height = heights[i];
	}

	return 1;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> l;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) cin >> board[i][j];
	}

	int ans = 0;
	for (int i = 0; i < n; i++) {
		vector<int> path(n);
		for (int j = 0; j < n; j++) path[j] = board[i][j];
		ans += isPath(path);
		for (int j = 0; j < n; j++) path[j] = board[j][i];
		ans += isPath(path);
	}

	cout << ans;
}
/*
 * 문제
 * n by n 지도에 높이가 적혀있다.
 * 이 지도에서 지나갈 수 있는 길이 몇 개인지 파악.
 * 길은 한 행이나 한 열 전체를 뜻함.
 *
 * 길을 지나갈 수 있으려면, 길에 속한 모든 칸의 높이가 같아야함
 * 또는, 경사로를 놓아서 지나갈 수 있는 길을 만들 수 있다.
 * 경사로의 높이는 항상 1이며, 길이는 L이다. 개수는 매우 많아 부족할 일 없다.
 *
 * 경사로를 놓을 수 있는 조건
 * 	경사로는 낮은 칸에 놓으며, L개의 연속된 칸에 경사로의 바닥이 모두 접해야 한다.
 * 	낮은 칸과 높은 칸의 높이 차이는 1이어야 한다.
 * 	경사로를 놓을 낮은 칸의 높이는 모두 같아야 하고, L개의 칸이 연속되어 있어야 한다.
 *
 * 경사로를 놓을 수 없는 경우
 * 	경사로를 놓은 곳에 또 경사로를 놓는 경우
 * 	낮은 칸과 높은 칸의 높이 차이가 1이 아닌 경우
 * 	낮은 지점의 칸의 높이가 모두 같지 않거나, L개가 연속되지 않은 경우
 * 	경사로를 놓다가 범위를 벗어나는 경우
 *
 * 입력
 * n, l
 * 지도 정보
 *
 * 출력
 * 지나갈 수 있는 길의 갯수
 *
 * //==아이디어==//
 * 길에서 i번째 칸과 i+1번째 칸의 높이가 다르면, 높이가 낮은 쪽의 위치를 확인
 * 만약, i가 더 낮다면, i-l+1 ~ i가 높이가 같은지 확인 (l개)
 * i+1가 더 낮다면, i+1 ~ i+l+2가 높이가 같은지 확인 (l개)
 *
 * 2n개에 대해서 높이를 비교하고 경사로를 놓을 수 있는지 확인
 * 2n * n * l = 200 * 100 * 100 = 2 * 10^6
 */