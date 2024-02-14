#include <bits/stdc++.h>
using namespace std;

int n;
// dp[i]: i번째 계단까지 올라섰을 때, 밟지 않을 계단의 합의 최솟값.
// 단, i번째 계단은 반드시 밟지 않는다.
int stairs[301], dp[301];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> stairs[i];

    dp[1] = stairs[1], dp[2] = stairs[2];
    for (int i = 3; i <= n; i++) {
        dp[i] = min(dp[i - 3], dp[i - 2]) + stairs[i];
    }

    int sum = 0;
    for (int i = 1; i <= n; i++)
        sum += stairs[i];
    cout << sum - min(dp[n - 1], dp[n - 2]) << "\n";
}