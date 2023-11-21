#include <bits/stdc++.h>

using namespace std;

int MAP[1001][1001];
int ans[1001][1001];
int n, m;
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    queue<pair<int, int>> q;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> MAP[i][j];
            if (MAP[i][j] == 2) q.push({i, j});
        }
    }

    while (!q.empty()) {
        int x = q.front().first, y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];

            if (nx < 0 || nx > n || ny < 0 || ny > m) continue;
            if (MAP[nx][ny] != 1) continue;
            if (ans[nx][ny] != 0) continue;

            ans[nx][ny] = ans[x][y] + 1;
            q.push({nx, ny});
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (MAP[i][j] == 1 && ans[i][j] == 0) ans[i][j]--;
            cout << ans[i][j] << " ";
        }
        cout << "\n";
    }
}