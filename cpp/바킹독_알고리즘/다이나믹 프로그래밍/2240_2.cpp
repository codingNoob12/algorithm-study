#include <bits/stdc++.h>
using namespace std;

int t, w;
int a[1001], d[1001][31][3];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> t >> w;
    for (int i = 1; i <= t; i++)
        cin >> a[i];

    for (int i = 1; i <= t; i++) {
        d[i][0][1] = d[i - 1][0][1] + (a[i] == 1);
        for (int j = 1; j <= w; j++) {
            if (i < j)
                break;
            for (int k = 1; k <= 2; k++)
                d[i][j][k] = max(d[i - 1][j - 1][k % 2 + 1], d[i - 1][j][k]) + (a[i] == k);
        }
    }

    int ans = 0;
    for (int i = 0; i <= w; i++)
        ans = max({ans, d[t][i][1], d[t][i][2]});
    cout << ans;
}
