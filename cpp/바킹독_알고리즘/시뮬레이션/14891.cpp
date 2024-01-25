#include <bits/stdc++.h>
using namespace std;

int gear[4][8];
int dx[] = {1, -1};
int rotation[4];
int k;

void rotate(int x, int dir) {
	int tmp[8] = {};
	int j = dir == 1 ? 7 : 1;
	for (int i = 0; i < 8; i++, j = (j + 1) % 8) tmp[i] = gear[x][j];
	for (int i = 0; i < 8; i++) gear[x][i] = tmp[i];
}

void bfs(int s, int d) {
	queue<int> q;
	bool vis[4] = {};
	q.push(s);
	rotation[s] = d;
	vis[s] = 1;

	while (!q.empty()) {
		int x = q.front();
		q.pop();

		for (int i = 0; i < 2; i++) {
			int nx = x + dx[i];
			if (nx < 0 || nx >= 4) continue;
			if (vis[nx]) continue;

			q.push(nx);
			vis[nx] = 1;

			int mn = min(nx, x), mx = max(nx, x);
			if (gear[mn][2] != gear[mx][6]) rotation[nx] = -rotation[x];
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	for (int i = 0; i < 4; i++) {
		string line;
		cin >> line;
		for (int j = 0; j < 8; j++) gear[i][j] = line[j] - '0';
	}

	cin >> k;
	while (k--) {
		fill(rotation, rotation + 4, 0);

		int x, dir;
		cin >> x >> dir;
		bfs(x - 1, dir);
		for (int i = 0; i < 4; i++) {
			if (!rotation[i]) continue;
			rotate(i, rotation[i]);
		}
	}

	int ans = 0;
	for (int i = 0; i < 4; i++) {
		if (!gear[i][0]) continue;
		ans += 1 << i;
	}

	cout << ans;
}
/*
 * 문제
 * 톱니바퀴는 총 4개가 있다.
 * 각 톱니바퀴는 톱니가 8개씩 존재한다.
 * 톱니의 극은 N과 S중 하나이다.
 * 톱니바퀴는 시계 방향과 시계 반대 방향으로 회전이 가능하다.
 *
 * 톱니바퀴 1,2,3,4 중 하나를 선택해서 방향을 결정하면 톱니바퀴 회전이 된다.
 *
 * 톱니바퀴A가 회전할 때, 옆에 있는 톱니바퀴B와 서로 맞닿은
 * 톱니의 극이 다르면 톱니바퀴A의 반대 방향으로 회전
 *
 * 입력
 * 1~4번 톱니바퀴의 상태가 주어진다.
 * 상태는 8개의 정수이며, 12시 방향부터 시계방향 순서대로 주어진다.
 * N극은 0, S극인 1
 *
 * 회전 횟수(K)가 주어진다.
 * 각각 톱니바퀴 번호와 회전 방향이 주어진다.
 * 시계 방향=1, 반시계 방향=-1
 *
 * 출력
 * 1번 톱니바퀴의 12시 방향이 N극이면 0점, S극이면 1점
 * 2번 톱니바퀴의 12시 방향이 N극이면 0점, S극이면 2점
 * 3번 톱니바퀴의 12시 방향이 N극이면 0점, S극이면 4점
 * 4번 톱니바퀴의 12시 방향이 N극이면 0점, S극이면 8점
 *
 * //==아이디어==//
 * 톱니바퀴의 회전과 인접한 톱니바퀴의 톱니가 서로 다른 극인지 판단하는 것을 구현해야한다.
 *
 * 인접한 톱니는 3시와 9시임. 배열의 인덱스는 2와 6임
 * 즉, 아래의 톱니의 극을 비교하면 된다.
 * (1, 2) - (2, 6)
 * (2, 2) - (3, 6)
 * (3, 6) - (4, 2)
 *
 * 회전은 모듈러 연산을 이용해서 이동시켜주면 된다.
 * 시계 방향 회전은 인덱스를 1씩 증가시켜주면 된다.
 * 반시계 방향 회전은 인덱스를 1씩 감소시켜주면 된다.
 */