#include <bits/stdc++.h>
using namespace std;

int n, m, g;
int board[1001][1001], vis[1001][1001];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
vector<int> zeros;

void bfs(int i, int j) {
    int cnt = 1;
    queue<pair<int, int>> q;
    vis[i][j] = g;
    q.push({i, j});

    while (!q.empty()) {
        int x, y;
        tie(x, y) = q.front();
        q.pop();

        for (int dir = 0; dir < 4; dir++) {
            int nx = x + dx[dir], ny = y + dy[dir];

            if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                continue;

            if (vis[nx][ny] != -1 || board[nx][ny])
                continue;

            q.push({nx, ny});
            vis[nx][ny] = g;
            cnt++;
        }
    }

    zeros.push_back(cnt);
    g++;
}

void increase(int i, int j) {
    unordered_set<int> s;
    for (int dir = 0; dir < 4; dir++) {
        int nx = i + dx[dir], ny = j + dy[dir];

        if (nx < 0 || nx >= n || ny < 0 || ny >= m)
            continue;

        if (board[nx][ny] || s.find(vis[nx][ny]) != s.end())
            continue;

        board[i][j] += zeros[vis[nx][ny]];
        board[i][j] %= 10;

        s.insert(vis[nx][ny]);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    for (int i = 0; i < 1001; i++)
        fill(vis[i], vis[i] + 1001, -1);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        string buf;
        cin >> buf;
        for (int j = 0; j < m; j++)
            board[i][j] = buf[j] - '0';
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (board[i][j] || vis[i][j] != -1)
                continue;

            bfs(i, j);
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!board[i][j]) {
                cout << 0;
                continue;
            }
            increase(i, j);
            cout << board[i][j];
        }
        cout << "\n";
    }
}