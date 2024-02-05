#include <bits/stdc++.h>
using namespace std;

const int BLANK = 0;
const int APPLE = 1;
const int SNAKE = -1;

int n, k, l, d, t;
char dir[10'001];
int board[101][101];
deque<pair<int, int>> dq;
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

void left() {
	d--;
	if (d < 0) d += 4;
}

void right() {
	d = (d + 1) % 4;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;
	while (k--) {
		int x, y;
		cin >> x >> y;
		board[x][y] = APPLE;
	}

	cin >> l;
	while (l--) {
		int x;
		char c;
		cin >> x >> c;
		dir[x] = c;
	}

	dq.push_front({1, 1});

	while (1) {
		switch (dir[t++]) {
			case 'L': left();
				break;
			case 'D': right();
				break;
		}

		int x, y;
		tie(x, y) = dq.front();
		int nx = x + dx[d], ny = y + dy[d];

		// 벽에 부딪히는 경우
		if (nx < 1 || nx > n || ny < 1 || ny > n) break;
		// 몸에 부딪히는 경우
		if (board[nx][ny] == SNAKE) break;

		// 사과가 없는 경우
		if (board[nx][ny] == BLANK) {
			int tail_x, tail_y;
			tie(tail_x, tail_y) = dq.back();
			board[tail_x][tail_y] = BLANK;
			dq.pop_back();
		}

		dq.push_front({nx, ny});
		board[nx][ny] = SNAKE;
	}

	cout << t;
}
/*
 * 문제
 * Dummy(도스 게임)
 * 뱀이 기어다니다가 사과 먹으면 길이가 길어짐. 벽이나 자신한테 박으면 겜 끝남
 *
 * n by n 정사각 보드에서 진행. 몇몇 칸에는 사과. 보드의 상하좌우 끝에는 벽.
 * 게임이 시작할 때 뱀은 맨위 맨좌측, 길이는 1이다. 그리고 오른쪽을 향함
 *
 * 뱀의 규칙 (매초)
 * 	몸길이를 늘려 머리를 다음 칸에 위치
 * 	만약 벽이나 자기 자신에 닿으면 게임 끝
 * 	만약 이동한 칸에 사과가 있으면, 사과가 없어지고 꼬리는 안움직임
 * 	만약 이동한 칸에 사과가 없으면, 몸 길이를 줄여서 꼬리가 위치한 칸을 비워준다.
 *
 * 게임이 몇 초에 끝나는지 계산
 *
 * 입력
 * 보드 크기(n)
 * 사과의 개수(k)
 *
 * 사과의 위치 (행, 열)
 *
 * 뱀의 방향 변환 횟수 l.
 * x, c => x초가 지난 후에 c방향으로 회전; c는 왼쪽('L'), 오른쪽('D')
 *
 * 출력
 * 몇초에 게임 끝남?
 *
 * //==아이디어==//
 * 그냥 구현문제인데?
 *
 * x가 10000이하라서 그냥 편하게 구현해도 될 듯?
 * 연산 횟수는 대충 x * n^2 정도? 그래서 10,000 * 100 * 100 = 10^8 (1억)정도로 1초 이내로 동작
 *
 * board에 정보를 저장하자. 0을 빈칸 1을 사과라 할까? -1이면 뱀이 있는 거라고 가정하자.
 * 초기 방향을 0이라 놓고 오른쪽은 +1, 왼쪽은 -1한다고 가정하자.
 * 4방향이니까 범위 벗어나면 다시 세팅하면 됨.
 * 그럼 dx, dy는 {0, 1, 0, -1}, {1, 0, -1, 0}로 놓으면 되겠네
 *
 * 그리고 dir배열에 x초에서의 방향을 기록해 놓으면 O(1)로 방향 바뀌는지 파악 가능
 *
 * 방향 바뀌면 left나 right함수 호출하고 안바뀌면 그냥 호출 안하면 됨
 * 이후, 벽이나 자신한테 박는지, 사과 먹는지 체크.
 * 사과 안먹었으면 뱀의 꼬리를 지워야함. 근데, 이게 좌표를 기억해 놓는 게 편해서 deque에다가 기록하자.
 * queue size도 최대 10,000 정도가 될거임
 * 왜냐하면 x가 10,000 이하니까, 이때까지 게임이 진행될 수 있고, 마지막으로 방향 바꾸고 100초 이내로
 * 게임 끝날 수 밖에 없음. 100초면 벽에 무조건 박으니까.
 *
 * 그래서 queue size도 최대 10,000개라고 봐도 될듯? pair가 저장되니까 80KB
 * dir배열은 10KB
 * board는 40KB
 * 그럼 거의 130KB정도? 메모리도 넉넉하네. 이대로 구현 ㄱㄱ
 */