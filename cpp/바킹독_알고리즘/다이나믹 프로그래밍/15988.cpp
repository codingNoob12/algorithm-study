#include <bits/stdc++.h>
using namespace std;

int tc, n, mod = 1'000'000'009;
int d[1'000'001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    d[1] = 1, d[2] = 2, d[3] = 4;
    for (int i = 4; i <= 1'000'000; i++)
        for (int j = 1; j <= 3; j++)
            d[i] = (d[i] + d[i - j]) % mod;

    cin >> tc;
    while (tc--) {
        cin >> n;
        cout << d[n] << "\n";
    }
}