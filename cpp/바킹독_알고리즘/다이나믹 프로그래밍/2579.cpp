#include <bits/stdc++.h>
using namespace std;

int n;
int stairs[301], dp[301];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> stairs[i];

    dp[1] = stairs[1], dp[2] = dp[1] + stairs[2];
    for (int i = 3; i <= n; i++) {
        dp[i] = max(dp[i - 3] + stairs[i - 1], dp[i - 2]) + stairs[i];
    }

    cout << dp[n];
}