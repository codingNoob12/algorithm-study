#include <bits/stdc++.h>
using namespace std;

int n, m;
int board[8][8]; //원본
int cp_board[8][8]; //복사본
vector<pair<int, int>> cctv; // cctv 위치 리스트
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

void monitor(int x, int y, int dir) {
	dir %= 4; //백트래킹하다보면 dir이 3을 넘어갈 수 있다.
	while (1) {
		x += dx[dir], y += dy[dir];
		if (x < 0 || x >= n || y < 0 || y >= m || cp_board[x][y] == 6) return;
		if (cp_board[x][y]) continue;
		cp_board[x][y] = 7;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int ans = 0;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
			if (!board[i][j]) ans++;
			else if (board[i][j] < 6) cctv.push_back({i, j});
		}
	}

	for (int tmp = 0; tmp < 1 << (2 * cctv.size()); tmp++) {
		for (int i = 0; i < n; i++) copy(board[i], board[i] + m, cp_board[i]);

		int brute = tmp;
		for (int i = 0; i < cctv.size(); i++) {
			int dir = brute % 4, x, y;
			tie(x, y) = cctv[i];
			switch (cp_board[x][y]) {
				case 1: monitor(x, y, dir);
					break;
				case 2: monitor(x, y, dir);
					monitor(x, y, dir + 2);
					break;
				case 3: monitor(x, y, dir);
					monitor(x, y, dir + 1);
					break;
				case 4: monitor(x, y, dir);
					monitor(x, y, dir + 1);
					monitor(x, y, dir + 2);
					break;
				default: monitor(x, y, dir);
					monitor(x, y, dir + 1);
					monitor(x, y, dir + 2);
					monitor(x, y, dir + 3);
			}
			brute /= 4;
		}

		int cnt = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) cnt += !cp_board[i][j];
		}
		ans = min(ans, cnt);
	}

	cout << ans;
}
/*
 * N by M 크기의 사무실에 CCTV를 설치한다.
 * CCTV의 종류는 5가지이다.
 * 1. 한방향만
 * 2. 반대인 두방향
 * 3. 인접한 두방향
 * 4. 인접한 세방향
 * 5. 모든 방향
 *
 * CCTV는 회전이 가능하다.
 *
 * K개의 CCTV를 배치했을 때, 사각지대의 최소 크기를 구해라
 *
 * 입력
 * 세로크기(N)과 가로크기(M)
 * 사무실 정보[공백은 0, 벽은 6이고 CCTV의 종류(1~5)]가 주어짐
 * CCTV의 최대 갯수는 8을 넘지 않음
 *
 * //== 아이디어 ==//
 * CCTV의 주방향(main direction)은 상하좌우로 4가지가 가능하다.
 * 단순하게 생각해보면, 이 모든 경우를 다 고려해보면 정답을 구할 수 있을 것이다.
 *
 * 이제, 방향을 숫자에 대응시켜 생각해보자.
 * CCTV가 3개일 경우 방향의 총 가짓수는 4^3 이고,
 * 000, 001, 002, 003, 010, ... 333의 방향이 가능하다.
 *
 * CCTV는 최대 8개 이므로 4^8(=65536)가지가 가능하다.
 * 각각의 경우에서 CCTV의 방향을 정하고 사각지대를 센 뒤에는 사무실 정보를 rollback 해줘야 한다.
 * 그래서 매번 원본값을 deep copy해야한다. 이를 위해, 원본과 연산에 사용할 배열을 분리하여 관리하자.
 *
 * 이는 O(NM)의 시간 복잡도를 요구한다.
 *
 * 그리고 해당 방향에 대해서 복사본에 감시중인 칸을 기록하자.
 * CCTV에서부터 해당 방향으로 벽을 만날때까지 루프를 돌아야함을 잊지 말자.
 * 이는 dx dy 테크닉으로 코드의 중복을 줄이면서 손쉽게 구현할 수 있다.
 *
 * 그런데, 이는 O(N)이나 O(M)의 시간 복잡도를 요구한다. 이미 O(NM)이 있기에 무시할 수 있다.
 *
 * 또, 사무실을 다 뒤지면서 CCTV를 찾는다면 시간이 더 걸리니 그냥 CCTV 위치 리스트를 도입하자.
 *
 * 그리고 난 뒤, 해당 케이스에서 사각 지대의 크기를 세야한다.
 * 이는 복사본의 모든 원소를 탐색해야하므로 O(NM)의 시간 복잡도를 필요로 한다.
 *
 * 따라서, 시간복잡도는 O(4^K * N * M)이고, 4^8 * 8 * 8 = 4,194,304이므로,
 * 1초 이내에 연산이 가능하다는 것을 알 수 있다.
 * 그러므로, 중복 연산을 포함하더라도 백트래킹으로 풀어낼 수 있다는 의미가 된다.
 * 즉, 굳이 그리디로 접근하지 않아도 된다.
 *
 * //==팁==//
 * 백트래킹은 재귀로 구현하는 것이 일반적이지만, 이 문제의 방향의 경우처럼 서로 독립된 관계라면,
 * n진법을 이용해 백트래킹을 구현할 수 있다.
 *
 * 10진법 수 x를 n진법으로 변환시에는 x % n => x /= n을 해나가면 된다.
 */