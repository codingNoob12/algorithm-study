#include <bits/stdc++.h>
using namespace std;

int n;
int h[1001][3], d[3][1001][3];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 3; j++)
            cin >> h[i][j];
    }

    int ans = 0x7f7f7f7f;
    // 시작 집의 색
    for (int c = 0; c < 3; c++) {
        copy(h[1], h[1] + 3, d[c][1]);
        for (int i = 2; i <= n; i++)
            fill(d[c][i], d[c][i] + 3, 0x7f7f7f7f);

        // 두번째 집 비용 계산
        for (int i = 0; i < 3; i++) {
            if (i == c)
                continue;
            d[c][2][i] = d[c][1][c] + h[2][i];
        }

        if (n > 2) {
            // 중간 ~ 마지막 집 비용 계산
            for (int i = 3; i <= n; i++) {
                for (int j = 0; j < 3; j++) {
                    if (i == n && j == c)
                        continue;
                    d[c][i][j] = min(d[c][i - 1][(j + 1) % 3], d[c][i - 1][(j + 2) % 3]) + h[i][j];
                }
            }
        }

        for (int i = 0; i < 3; i++)
            ans = min(ans, d[c][n][i]);
    }

    cout << ans;
}