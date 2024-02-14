#include <bits/stdc++.h>
using namespace std;

int n, mod = 1'000'000'000;
long long d[101][10];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    fill(d[1] + 1, d[1] + 10, 1);

    cin >> n;
    for (int i = 2; i <= n; i++) {
        for (int j = 0; j <= 9; j++) {
            if (j != 0)
                d[i][j] += d[i - 1][j - 1];
            if (j != 9)
                d[i][j] += d[i - 1][j + 1];
            d[i][j] %= mod;
        }
    }

    long long ans = 0;
    for (int i = 0; i < 10; i++)
        ans += d[n][i];
    cout << ans % mod;
}