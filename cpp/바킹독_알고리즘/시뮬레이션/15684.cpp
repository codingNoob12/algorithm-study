#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int n, m, h;
bool ladder[31][11];
vector<pair<int, int>> coords;

bool isOver() {
    for (int j = 1; j <= n; j++) {
        int y = j;
        for (int i = 1; i <= h; i++) {
            if (ladder[i][y])
                y++;
            else if (ladder[i][y - 1])
                y--;
        }
        if (y != j)
            return 0;
    }
    return 1;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> h;
    while (m--) {
        int a, b;
        cin >> a >> b;
        ladder[a][b] = 1;
    }

    for (int i = 1; i <= h; i++) {
        for (int j = 1; j < n; j++) {
            if (ladder[i][j - 1] || ladder[i][j] || ladder[i][j + 1])
                continue;
            coords.push_back({i, j});
        }
    }

    if (isOver()) {
        cout << 0;
        return 0;
    }

    int sz = coords.size(), ans = 0x7f7f7f7f;
    for (int i = 0; i < sz; i++) {
        ladder[coords[i].X][coords[i].Y] = 1;
        if (isOver())
            ans = min(ans, 1);
        for (int j = i + 1; j < sz; j++) {
            ladder[coords[j].X][coords[j].Y] = 1;
            if (isOver())
                ans = min(ans, 2);
            for (int k = j + 1; k < sz; k++) {
                ladder[coords[k].X][coords[k].Y] = 1;
                if (isOver())
                    ans = min(ans, 3);
                ladder[coords[k].X][coords[k].Y] = 0;
            }
            ladder[coords[j].X][coords[j].Y] = 0;
        }
        ladder[coords[i].X][coords[i].Y] = 0;
    }

    if (ans > 3)
        ans = -1;
    cout << ans;
}
/*
 * 문제
 * 사다리 게임은 n개의 세로선과 m개의 가로선으로 이루어져 있다.
 * 인접한 세로선 사이에는 가로선을 놓을 수 있다.
 * 각각의 세로선마다 가로선을 놓을 수 있는 위치의 개수는 h
 * 모든 세로선이 같은 위치를 가진다.
 *
 * i번 세로선의 결과가 i번이 나오도록 가로선을 추가하자
 *
 * 입력
 * 세로선 개수(n), 가로선 개수(m), 세로선마다 가로선을 놓을 수 있는 위치 개수(h)
 * m개의 가로선 정보(a, b) => b번 세로선과 b+1번 세로선을 a번 가로선 위치에서
 * 연결 세로선과 가로선은 1부터 시작 입력으로 주어지는 가로선이 서로 연속하는
 * 경우는 없다.
 *
 * 출력
 * i번 세로선의 결과가 i번이 나오도록 조작하려면, 추가해야하는 가로선 개수의
 * 최솟값 출력. 만약, 정답이 3보다 큰 값이면 -1을 출력. 불가능한 경우에도 -1을
 * 출력
 *
 * 아이디어
 * 그럼 모든 가로선 중에서 추가할 3개를 선택하고 i번째 세로선의 결과가 i인지
 * 파악하면 될 듯함 선택은 mC3 + mC2 + mC1 + mC0으로 최대 3,280,726가지가 된다.
 *
 * 사다리를 어떻게 표현할 지가 중요한 포인트가 될 듯함
 * 그냥 2차원 배열에다가 (a, b)면, 세로선 b와 b+1이 a번 가로선을 통해 연결되어
 * 있다고 표시하면
 *
 * 세로로 내려가다가 (x, b)와 (x, b-1)중 1인 지점이 있으면 b+1이나 b-1로
 * 이동하도록 하면 된다. 이것은 h로 최대 30이 된다.
 *
 * 하지만, 초기화시 (n - 1) * h의 시간 복잡도가 필요함.
 *
 * 즉, 3,280,726 * 30 * 10 = 984,217,800으로 시간 초과 발생
 *
 * 모든 경우를 고려해서 문제가 발생한 것.
 * 따라서, 불가능한 경우는 애초부터 고려하지 않도록 하자.
 *
 * 그래도 복사본을 초기화는 과정이 들어가면 시간 초과가 발생할 수 있음.
 * 그냥 0 ~ 3개를 선택해서 원본에서 추가했다가 삭제하도록 백트래킹을 직접
 * 구현하는 게 좋아보임
 *
 * 그럼 3,280,726 * 30 * 3 = 295,265,340으로 1초 이내에 결과가 나옴
 */