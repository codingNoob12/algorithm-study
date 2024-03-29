#include <bits/stdc++.h>
using namespace std;

int n, x, y, d, g;
bool board[102][102];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, -1, 0, 1};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    while (n--) {
        cin >> x >> y >> d >> g;
        board[y][x] = 1;
        x += dx[d], y += dy[d];
        board[y][x] = 1;
        vector<int> dir;
        dir.push_back(d);
        while (g--) {
            for (int i = dir.size() - 1; i >= 0; i--) {
                int nd = (dir[i] + 1) % 4;
                x += dx[nd], y += dy[nd];
                board[y][x] = 1;
                dir.push_back(nd);
            }
        }
    }
    int cnt = 0;
    for (int i = 0; i <= 100; i++) {
        for (int j = 0; j <= 100; j++) {
            if (board[i][j] && board[i][j + 1] && board[i + 1][j] && board[i + 1][j + 1])
                cnt++;
        }
    }
    cout << cnt;
}
/*
* 문제
드래곤 커브는 다음의 세가지 속성으로 이루어져 있음. x축은 →방향, y축은 ↓방향.
1. 시작점
2. 시작방향
3. 세대

0세대 드래곤 커브는 (0, 0)에서 시작하고 시작 방향은 오른쪽인 길이가 1인 선분

1세대 드래곤 커브는 0세대 드래곤 커브의 끝 점을 기준으로 시계 방향으로 90도 회전시킨 다음
0세대 드래곤 커브의 끝점에 붙인 것이다. 끝 점이란 선분을 타고 이동했을 때, 가장 먼 거리에 있는 점이다.

즉, K세대 드래곤 커브는 K-1세대 드래곤 커브를 끝 점을 기준으로 90도 시계방향 회전시킨 다음,
그것을 끝 점에 붙인 것이다.

크기가 100x100인 격자 위에 드래곤 커브가 N개 있다.
이때, 1x1인 정사각형의 네 꼭짓점이 모두 드래곤 커브의 일부인 정사각형의 개수를 구하는 프로그램
격자의 좌표는 (x, y)로 나타내며, 0 <= x, y <= 100만 유효한 좌표이다.

* 입력
드래곤 커브의 수(n), 드래곤 커브 정보(x, y, d, g)
(x, y)는 드래곤 커브의 시작점, d는 시작 방향, g는 세대

입력으로 주어지는 드래곤 커브는 격자 밖으로 벗어나지 않는다.

방향은 0 ~ 3중 하나이고 다음을 의미한다.
0: x좌표가 증가하는 방향 (→)
1: y좌표가 감소하는 방향 (↑)
2: x좌표가 감소하는 방향 (←)
3: y좌표가 증가하는 방향 (↓)

* 출력
크기가 1x1인 정사각형의 네 꼭짓점이 모두 드래곤 커브의 일부인 것의 개수

? 아이디어
*입력으로 드래곤 커브 n개가 주어졌을 때, (x, y, d, g)가 주어진다.
!이 때의 g가 현재 세대가 아니라 앞으로 구해야하는 세대의 갯수를 의미함을 잊지말자.
이걸 설명도 안해줘서 ㄹㅇ 헤메다가 다른 사람 코드보고 알게됐음.

*K세대는 K-1세대의 정보를 바탕으로 알 수 있다.
이전 세대의 마지막 점이 다음 세대의 시작점이다.
이전 세대의 방향들을 역순으로 꺼내면서 각 방향의 (dir + 1) % 4를 해주면, 다음 방향이 된다.
  끝 점을 기준으로 시계 방향으로 90도 돌려주면 선분이 나온다. 현재 세대의 시작점을 기준으로 따라가려면
  끝점까지 따라가려면, 방향은 반시계가 됨을 알 수 있다.

위의 두 성질을 이용해서 다음 세대의 정보를 파악할 수 있다.

보드에다가 바로 마스킹하는 작업을 모두 끝낸 후, 사각형의 갯수를 구하자.

*(x,y), (x+1,y), (x,y+1), (x+1,y+1)이 모두 색칠되어 있으면 사각형이다.
이를 바탕으로 2중 루프를 돌면서 사각형의 갯수를 파악할 수 있다.

n개의 드래곤 커브가 주어지고 각각 g개 세대를 구한다. 이후, 2중 루프를 통해 답을 구하게 된다.
최대 연산 횟수는 20 * 10 * 1023 + 100 * 100 = 214,600으로 1초 이내에 연산 종료
*/