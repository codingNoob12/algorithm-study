#include <bits/stdc++.h>
using namespace std;

const char BLANK = '.';
const char WALL = '*';
const char DOCUMENT = '$';

char board[102][102];
bool vis[102][102];
string buf;
int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1}, w, h, tc;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> tc;
    while (tc--) {
        bool keys[26] = {};
        queue<pair<int, int>> q, wq[26];

        cin >> h >> w;
        for (int i = 0; i < h + 2; i++) {
            fill(board[i], board[i] + w + 2, BLANK);
            fill(vis[i], vis[i] + w + 2, 0);
        }

        for (int i = 1; i <= h; i++) {
            cin >> buf;
            int j = 1;
            for (auto c : buf)
                board[i][j++] = c;
        }

        cin >> buf;
        for (char k : buf)
            keys[k - 'a'] = 1;

        q.push({0, 0});
        vis[0][0] = 1;

        int cnt = 0;
        while (!q.empty()) {
            int x, y;
            tie(x, y) = q.front();
            q.pop();

            for (int dir = 0; dir < 4; dir++) {
                int nx = x + dx[dir], ny = y + dy[dir];

                if (nx < 0 || nx > h + 1 || ny < 0 || ny > w + 1)
                    continue;

                if (board[nx][ny] == WALL || vis[nx][ny])
                    continue;

                if (islower(board[nx][ny])) { // 열쇠 발견
                    int k = board[nx][ny] - 'a';
                    keys[k] = 1;

                    while (!wq[k].empty()) {
                        q.push(wq[k].front());
                        wq[k].pop();
                    }
                } else if (isupper(board[nx][ny])) { // 문 발견
                    int k = board[nx][ny] - 'A';
                    if (!keys[k]) {
                        wq[k].push({nx, ny});
                        continue;
                    }
                } else if (board[nx][ny] == DOCUMENT) // 문서 발견
                    cnt++;

                q.push({nx, ny});
                vis[nx][ny] = 1;
            }
        }

        cout << cnt << "\n";
    }
}
/*
* 문제
1층 빌딩에 침입해서 중요 문서 훔치기.
평면도에는 문서의 위치가 모두 나타나 있다.
빌딩의 문은 모두 잠겨있어, 문을 열려면 열쇠가 필요.
일부 열쇠를 이미 가지고 있고, 일부 열쇠는 빌딩 바닥에 놓여있음.
상하좌우로만 이동 가능.

훔칠 수 있는 문서의 최대 개수 구하기

* 입력
테스트 케이스 개수
지도의 높이(h), 너비(w) => h by w 빌딩 정보
! '.': 빈공간
! '*': 벽
! '$': 훔쳐야할 문서
! 알파벳 대문자: 문
! 알파벳 소문자: 열쇠; 해당 문자의 대문자인 모든 문을 열 수 있다.
현재 보유중인 열쇠 목록. 공백없이 주어짐; 하나도 없으면 0이 주어짐

! 처음에는 빌딩 밖에 있음.
! 빌딩 가장자리의 벽이 아닌 곳을 통해 빌딩 안팎으로 드나들 수 있다.
! 각각의 문을 열 수 있는 열쇠의 갯수는 0개, 1개, 또는 그 이상.
! 각각의 열쇠에 대해서도 열 수 있는 문의 갯수는 0개, 1개, 또는 그 이상.
! 열쇠는 여러 번 사용할 수 있다.

* 출력
각 테스트 케이스마다 훔칠 수 있는 문서의 최대 개수 출력

? 아이디어
가능한 모든 칸을 이동하면서 문서를 훔칠 수 있나 확인해야함. => bfs
근데, 빌딩 정보외에 바깥 줄을 건물 밖이라고 설정하면, bfs로 한번에 들어갈 수 있는 위치를 파악할 수 있다.
즉, 일일히 들어갈 수 있는지를 파악하고 시작점으로 설정해주지 않아도 된다.

열쇠 보유 목록을 확인해야함. 배열이 적당해보임.
string 형태로 가지고 있으면 시간복잡도가 O(K)임. 이게 열쇠 다 가지고 있고 모든 칸에서 검증한다고 가정하면,
100 * 100 * 26 = 260,000으로, 테스트케이스가 100을 넘지 않아 26,000,000보단 적어서 1초 이내에 돌아가지만,
비효율적이라, 배열에 넣어놓고 O(1)로 접근하는게 나을 듯?
근데 이건 매번 초기화해야되서 지역 변수로 가지고 있는게 좋아보임.

인접 칸으로만 이동가능하니 dx, dy테크닉 필요하고, bfs니 큐가 필요하고, 방문 여부도 기록해야한다.
그리고, 문서가 있는 칸에 방문한 횟수도 기록해야한다. 열쇠를 만나면 set에 추가하고, 벽이면 방문 안하고,
재방문 안하고, 빈칸이나 문서가 있는 칸만 방문한다고 가정하자.
그리고, 열쇠 주우면 열쇠 추가하고, 문 못열면 대기큐

즉, 전역으로 board, dx, dy, vis, tc, h, w, keyStr정도가 필요하고
지역으로 q, waitQ, cnt정도가 필요함
*/