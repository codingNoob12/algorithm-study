#include <bits/stdc++.h>
using namespace std;

const char BLANK = '.';
const int N = 12;
const int M = 6;

char board[N][M];
int ans;
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
bool vis[N][M];
queue<pair<int, int>> q;

int bfs(int i, int j) {
	int cnt = 1;
	q.push({i, j});
	vis[i][j] = 1;

	while (!q.empty()) {
		int x, y;
		tie(x, y) = q.front();
		q.pop();

		for (int dir = 0; dir < 4; dir++) {
			int nx = x + dx[dir], ny = y + dy[dir];
			if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
			if (board[nx][ny] != board[i][j] || vis[nx][ny]) continue;
			vis[nx][ny] = vis[x][y];
			cnt++;
			q.push({nx, ny});
		}
	}
	return cnt;
}

void pop_puyo(int i, int j) {
	q.push({i, j});
	const char C = board[i][j];

	while (!q.empty()) {
		int x, y;
		tie(x, y) = q.front();
		q.pop();

		board[x][y] = BLANK;
		for (int dir = 0; dir < 4; dir++) {
			int nx = x + dx[dir], ny = y + dy[dir];
			if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
			if (board[nx][ny] != C) continue;
			q.push({nx, ny});
		}
	}
}

void fall() {
	for (int j = 0; j < M; j++) {
		int idx = N - 1;
		char column[N] = {};
		fill(column, column + N, BLANK);

		for (int i = N - 1; i >= 0; i--) {
			if (board[i][j] == BLANK) continue;
			column[idx--] = board[i][j];
		}

		for (int i = 0; i < N; i++) board[i][j] = column[i];
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) cin >> board[i][j];
	}

	while (1) {
		for (int i = 0; i < N; i++) fill(vis[i], vis[i] + M, 0);

		bool is_break = 1;
		for (int i = N - 1; i >= 0; i--) {
			for (int j = 0; j < M; j++) {
				if (board[i][j] == BLANK) continue;
				if (bfs(i, j) < 4) continue;
				pop_puyo(i, j);
				is_break = 0;
			}
		}

		if (is_break) break;
		ans++;
		fall();
	}

	cout << ans;
}
/*
 * 문제
 * 뿌요의 색깔은 여러 개다.
 * 뿌요는 바닥이나 다른 뿌요에 닿을 때까지 떨어진다.
 *
 * 뿌요가 내려온 뒤, 같은 색 뿌요가 4개 이상 상하좌우로 연결 -> 연결된 같은 색 뿌요들이 한 번에 없어짐
 * 뿌요들이 없어진 후, 위에 다른 뿌요들이 있었다면, 아래로 떨어진다.
 *
 * 또 뿌요가 떨어지고 같은 색 뿌요가 4개 이상 연결되면, 다시 사라진다.
 *
 * 이렇게 터진 후 뿌요들이 내려오고 다시 터짐을 반복할 때마다 1연쇄씩 늘어난다.
 *
 * 터질 수 있는 뿌요가 여러 그룹이었다면 동시에 터져야 하고
 * 여러 그룹이 터지더라도 한번의 연쇄가 추가 된다.
 *
 * 상대방의 필드가 주어졌을 때, 몇 연쇄가 일어나는지 확인
 *
 * 입력
 * 12x6의 필드가 주어진다.
 * '.'은 빈공간, '.'이 아닌 것은 뿌요 색깔
 * 'R': 빨강, 'G': 초록, 'B': 파랑, 'P': 보라, 'Y': 노랑
 * 뿌요는 전부 아래로 떨어진 뒤의 상태.
 *
 * 출력
 * 몇연쇄? 안터지면 0 출력
 *
 * //==아이디어==//
 * bfs로 같은 색깔인 뿌요가 4개 이상 연결되어 있는지 확인 => 없애기
 *
 * 전부 없앴으면, 아래로 내려주기. (포인터 2개로 옮기기)
 *
 * 다시 없애고 내리기 반복
 */