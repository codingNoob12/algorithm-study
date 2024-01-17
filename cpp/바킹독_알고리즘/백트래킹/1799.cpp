#include <bits/stdc++.h>
using namespace std;

int n, ans[2];
vector<pair<int, int>> board[2][20];
bool is_used[2][20];

void solve(int k, int cnt, int color) {
	if (k == 2 * n) {
		ans[color] = max(ans[color], cnt);
		return;
	}

	for (auto pos : board[color][k]) {
		int x, y;
		tie(x, y) = pos;
		if (is_used[color][x + y]) continue;
		is_used[color][x + y] = true;
		solve(k + 1, cnt + 1, color);
		is_used[color][x + y] = false;
	}
	solve(k + 1, cnt, color);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int b;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> b;
			if (b) board[(i + j) % 2][i - j + n - 1].push_back({i, j});
		}
	}
	solve(0, 0, 0);
	solve(0, 0, 1);
	cout << ans[0] + ans[1];
}
/*
 * 입력
 * 체스판 크기(n)
 * n by n 체스판 정보
 *   0: 비숍을 놓을 수 없는 곳
 *   1: 비숍을 놓을 수 있는 곳
 *
 * 출력: 비숍이 서로 잡을 수 없도록 놓을 수 있는 비숍의 최대 갯수
 *
 * 비숍은 대각선에 있는 기물을 잡을 수 있다.
 * 대각선 판단: [좌];x + y, [우];x - y가 동일한지
 *
 * 비숍이 (x, y)에 존재하는지? 대각선에 존재하는지?
 *
 * 모든 경우를 선택지별로 다 따져보기 => 백트래킹
 *
 * +) 모든 케이스를 한번에 처리하는 것은 시간초과가 난다. [O((N^2)!); 대략 100!]
 *
 * 어떻게 경우의 수를 줄일 수 있을까?
 *
 * 비숍의 특성을 이용해보자
 * 비숍은 체스판에서 다른 색 칸의 기물은 절대 잡을 수 없다.
 * 그렇다면, 검정색과 흰색으로 분리해보면, 확인해보아야 하는 칸 수가 줄어든다.
 *
 * 또, 대각선 중 한쪽 방향에 포함되는 좌표들을 묶어서 관리하면,
 * 해당 대각선에서 1개를 선택하거나 선택하지 않는 것으로 모든 경우의 수를 고려할 수 있다.
 *
 * 모든 칸에 방문하지 않아도 되므로 시간 복잡도가 더욱 줄어든다.
 */