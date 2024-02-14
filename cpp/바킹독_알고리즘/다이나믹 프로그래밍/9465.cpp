#include <bits/stdc++.h>
using namespace std;

int tc, n;
int s[3][100'001], d[3][100'001][2];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> tc;
    while (tc--) {
        cin >> n;
        for (int i = 1; i <= 2; i++) {
            for (int j = 1; j <= n; j++)
                cin >> s[i][j];
        }

        int ans = 0;
        for (int i = 1; i <= n; i++) {
            d[1][i][0] = max({d[1][i - 1][0], d[1][i - 1][1], d[2][i - 1][0], d[2][i - 1][1]});
            d[1][i][1] = max(d[1][i - 1][0], d[2][i - 1][1]) + s[1][i];
            d[2][i][0] = max(d[1][i][0], d[1][i][1]);
            d[2][i][1] = max(d[1][i - 1][1], d[2][i - 1][0]) + s[2][i];

            for (int x = 1; x <= 2; x++) {
                for (int y = 0; y < 2; y++)
                    ans = max(ans, d[x][i][y]);
            }
        }
        cout << ans << "\n";
    }
}