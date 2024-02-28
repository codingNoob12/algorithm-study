#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;

int m, n;
int universe[101][10001];
int sorted[101][10001];
pair<int, int> er[101][10001];

bool solve(int i, int j) {
    for (int x = 0; x < n; x++) {
        if (er[i][x].X != er[j][x].X || er[i][x].Y != er[j][x].Y)
            return 0;
    }
    return 1;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> m >> n;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> universe[i][j];
            sorted[i][j] = universe[i][j];
        }
        sort(sorted[i], sorted[i] + n);
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            auto tmp = equal_range(sorted[i], sorted[i] + n, universe[i][j]);
            er[i][j] = {tmp.X - sorted[i], tmp.Y - sorted[i]};
        }
    }

    int ans = 0;
    for (int i = 0; i < m; i++) {
        for (int j = i + 1; j < m; j++) {
            ans += solve(i, j);
        }
    }

    cout << ans;
}