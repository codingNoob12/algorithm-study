#include <bits/stdc++.h>
using namespace std;

int n;
int board1[20][20];
int board2[20][20];

// 시계 방향 90도 회전
void rotate() {
	int tmp[20][20] = {};
	for (int i = 0; i < n; i++) copy(board2[i], board2[i] + n, tmp[i]);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) board2[i][j] = tmp[n - 1 - j][i];
	}
}

void merge(int dir) {
	while (dir--) rotate();
	for (int i = 0; i < n; i++) {
		int tmp[20] = {}, idx = 0;
		for (int j = 0; j < n; j++) {
			if (!board2[i][j]) continue;
			if (!tmp[idx]) tmp[idx] = board2[i][j];
			else if (tmp[idx] == board2[i][j]) tmp[idx++] *= 2;
			else tmp[++idx] = board2[i][j];
		}
		copy(tmp, tmp + n, board2[i]);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) cin >> board1[i][j];
	}

	int mx = 0;
	for (int tmp = 0; tmp < 1 << (2 * 5); tmp++) {
		for (int i = 0; i < n; i++) copy(board1[i], board1[i] + n, board2[i]);

		int brute = tmp;
		for (int i = 0; i < 5; i++) {
			int dir = brute % 4;
			merge(dir);
			brute /= 4;
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) mx = max(mx, board2[i][j]);
		}
	}

	cout << mx;
}
/*
 * 입력
 * 보드의 크기(N)
 * 게임판의 초기 상태. 빈칸은 0, 이외의 값은 블록
 * 블록 값은 2 ~ 1024인 2의 거듭제곱꼴
 *
 * 출력
 * 최대 5번 이동시켜 얻을 수 있는 가장 큰 블록
 *
 * 조건
 * 상하좌우로 모든 블록을 움직일 수 있다.
 * 같은 값을 갖는 두 블록이 충돌하면, 하나로 합쳐진다.
 * 이미 합쳐진 블록은 또 다른 블록과 합쳐질 수 없다.
 * 새블록이 추가되지는 않는다.
 *
 * //==아이디어==//
 * 5번의 각 방향을 결정해야함.-> 백트래킹
 *
 * 상하좌우로 블록을 이동시키며 합쳐야함
 * 이동시에는 기준점이 각각 상하좌우로 기준점이 달라져 따로 구현해야한다.
 * 이 상황은 기준점이 달라 문제가 생긴 것으로 회전을 통해 기준점을 한 쪽으로 맞춰줄 수 있다.
 * 그렇다면, 기준점을 좌측으로 하자.
 *
 * 방향에 맞게 회전을 시키고
 * 각 행에 대해 좌측으로 블록을 이동시킨디.
 *
 * 결과적으로 게임판이 돌아간 생태라 되돌려주어야 할 것 같다.
 *
 * 하지만, 백트래킹으로 모든 회전 방향을 고려하고 있으므로 되돌려주지 않아도 정상적으로 동작할 것이다.
 *
 * 시간 복잡도
 * 4^5 * O(n^2) = 1024 * 400 = 409600
 */