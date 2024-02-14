#include <bits/stdc++.h>
using namespace std;

int n, cnt;
int dp[3'000'001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 1; i < n; i++) {
        if (!dp[3 * i])
            dp[3 * i] = dp[i] + 1;
        else
            dp[3 * i] = min(dp[3 * i], dp[i] + 1);

        if (!dp[2 * i])
            dp[2 * i] = dp[i] + 1;
        else
            dp[2 * i] = min(dp[2 * i], dp[i] + 1);

        if (!dp[i + 1])
            dp[i + 1] = dp[i] + 1;
        else
            dp[i + 1] = min(dp[i + 1], dp[i] + 1);
    }

    cout << dp[n];
}