#include <bits/stdc++.h>
using namespace std;

int n, m;
int board[1001][1001];
bool vis[1001][1001];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

void bfs(int i, int j) {
    int cnt = 1;
    queue<pair<int, int>> q;
    set<pair<int, int>> s;
    vis[i][j] = 1;
    q.push({i, j});

    while (!q.empty()) {
        int x, y;
        tie(x, y) = q.front();
        q.pop();

        for (int dir = 0; dir < 4; dir++) {
            int nx = x + dx[dir], ny = y + dy[dir];

            if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                continue;

            if (board[nx][ny]) {
                s.insert({nx, ny});
                continue;
            }

            if (vis[nx][ny])
                continue;

            q.push({nx, ny});
            vis[nx][ny] = 1;
            cnt++;
        }
    }

    for (auto it = s.begin(); it != s.end(); it++) {
        int x, y;
        tie(x, y) = *it;
        board[x][y] += cnt;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        string buf;
        cin >> buf;
        for (int j = 0; j < m; j++)
            board[i][j] = buf[j] - '0';
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (board[i][j] || vis[i][j])
                continue;

            bfs(i, j);
        }
    }

    for (int x = 0; x < n; x++) {
        for (int y = 0; y < m; y++)
            cout << board[x][y] % 10;
        cout << "\n";
    }
}