#include <bits/stdc++.h>
using namespace std;

const int n = 5;
int board1[n][n][n];
int board2[n][n][n];
int board3[n][n][n];
int dx[] = {1, -1, 0, 0, 0, 0};
int dy[] = {0, 0, 1, -1, 0, 0};
int dz[] = {0, 0, 0, 0, 1, -1};
//dist: 125 * 4 = 500 => 로컬

// 시계 방향 90도 회전
void rotate(int x) {
	int tmp[n][n] = {};
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) tmp[i][j] = board2[x][i][j];
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) board2[x][i][j] = tmp[n - 1 - j][i];
	}
}

// 입구: (0, 0, 0), 출구: (n-1, n-1, n-1)
int bfs() {
	if (!board3[0][0][0] || !board3[n - 1][n - 1][n - 1]) return -1;

	queue<tuple<int, int, int>> q;
	int dist[n][n][n] = {};
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			fill(dist[i][j], dist[i][j] + n, -1);
		}
	}

	q.push({0, 0, 0});
	dist[0][0][0] = 0;

	while (!q.empty()) {
		int x, y, z;
		tie(x, y, z) = q.front();
		q.pop();

		if (make_tuple(x, y, z) == make_tuple(n - 1, n - 1, n - 1)) return dist[x][y][z];

		for (int dir = 0; dir < 6; dir++) {
			int nx = x + dx[dir], ny = y + dy[dir], nz = z + dz[dir];
			if (nx < 0 || nx >= n || ny < 0 || ny >= n || nz < 0 || nz >= n) continue;
			if (!board3[nx][ny][nz] || dist[nx][ny][nz] != -1) continue;
			q.push({nx, ny, nz});
			dist[nx][ny][nz] = dist[x][y][z] + 1;
		}
	}

	return -1;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) cin >> board1[i][j][k];
		}
	}

	int ans = INT_MAX;
	for (int tmp = 0; tmp < 1 << (2 * n); tmp++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				copy(board1[i][j], board1[i][j] + n, board2[i][j]);
			}
		}

		// 각각의 판 회전
		int brute = tmp;
		for (int i = 0; i < 5; i++) {
			int dir = brute % 4;
			while (dir--) rotate(i);
			brute /= 4;
		}

		vector<int> st;
		for (int i = 0; i < n; i++) st.push_back(i);

		do {
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					for (int k = 0; k < n; k++) board3[i][j][k] = board2[st[i]][j][k];
				}
			}
			int d = bfs();
			if (d != -1) ans = min(d, ans);
		} while (next_permutation(st.begin(), st.end()));
	}
	if (ans != INT_MAX) cout << ans;
	else cout << -1;
}
/*
 * 문제
 * 3차원 미로 탈출
 *
 * 5x5 크기의 판이 5개 주어진다.
 * 하얀 칸: 참가자 O
 * 검은 칸: 참가자 X
 *
 * 참가자는 판을 회전시킬 수 있다. (시계, 반시계)
 *
 * 회전 완료 후, 5개 판을 쌓는다. => 5x5x5 크기의 미로 큐브 (쌓는 순서를 결정해야함)
 * 입구: 참가자가 임의로 선택한 큐브 꼭짓점에 위치
 * 출구: 입구와 면을 공유하지 않는 큐브 꼭짓점에 위치
 * 이동 가능한 칸만 방문 가능
 * 미로를 최단거리로 탈출해야 우승
 *
 * 즉, 입구와 출구는 대각선에 위치함
 *
 * 주어진 판에서 가장 적은 횟수로 출구에 도달하는 방법
 *
 * 입력
 * 1 ~ 25줄 => 판 정보
 * 0은 이동 불가, 1은 이동 가능
 *
 * 출력
 * 최단 거리, 탈출 불가능하면 -1
 *
 * //==아이디어==//
 * bfs인데... 브루트 포스까지 섞인듯?
 * 판을 돌리는 거하고 각각에 대해 bfs를 해줘야 문제 풀리겠는데?
 *
 * 그리고, 입구와 출구가 임의로 선택되어야함.
 * 입구와 출구는 백트래킹으로 선택하고
 * 판 돌리는 거는 4방향이니까 4진법으로 회전 방향 다 고려하게 만들면 되겠네
 *
 * 그냥 회전 시킬꺼니까 (0, 0, 0)과 (n-1, n-1, n-1)을 입구와 출구로 놓으면 모든 경우의 수를 고려 O
 *
 * 그래도, 판을 쌓는 순서를 결정해야 해서 백트래킹 해야함
 *
 * 2초 이내로 가능한가?
 *
 * 4^5 * 5! = 1024 * 120 = 122,880
 * bfs쓰면 122,880 * 125 = 15,360,000로 1초 이내 연산되네
 *
 * 그냥 구현 복잡한 bfs문제라는 거 파악 완료.
 *
 * //==구현==//
 * 1. 회전
 * 	복사본에서 90도 시계 방향 회전시키고 옮겨주면 됨 (M^2)
 * 2. 적층
 * 	그냥 백트래킹으로 회전된 층을 선택해서 한 층씩 복사해서 완성
 * 3. bfs
 * 	일일히 다 방문해봐야하니까 (N^2)
 */