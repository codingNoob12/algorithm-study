#include <bits/stdc++.h>

using namespace std;

int box[1000][1000];
int m, n;
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

bool isValidPosition(int x, int y) {
    if (x < 0 || x >= m || y < 0 || y >= n) return false;
    if (box[x][y] == 0) return true;
    return false;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) cin >> box[i][j];
    }

    queue<pair<int, int>> q;
    int tot = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (box[i][j] == 1) q.push({i, j});
            if (box[i][j] != -1) tot++;
        }
    }

    if (tot == q.size()) {
        cout << 0;
        return 0;
    }
    while (!q.empty()) {
        int x = q.front().first, y = q.front().second;
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (isValidPosition(nx, ny)) {
                box[nx][ny] = box[x][y] + 1;
                q.push({nx, ny});
            }
        }
        q.pop();
    }

    int ans = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (!box[i][j]) {
                cout << -1;
                return 0;
            }
            if (box[i][j] != -1) ans = max(ans, box[i][j]);
        }
    }
    cout << ans - 1;
}