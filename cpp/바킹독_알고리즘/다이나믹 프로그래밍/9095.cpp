#include <bits/stdc++.h>
using namespace std;

int tc, n;
int dp[12];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> tc;
    dp[1] = 1, dp[2] = 2, dp[3] = 4;
    for (int i = 4; i < 12; i++)
        dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];

    while (tc--) {
        cin >> n;
        cout << dp[n] << "\n";
    }
}
/*
* dp를 이용한 풀이
dp[4]를 생각해보자.
1+1+1+1, 3+1, 2+1+1, 1+2+1 => (3의 표현 + 1)
1+1+2, 2+2 => (2의 표현 + 2)
1+3 => (1의 표현 + 3)
즉, 마지막 숫자를 1, 2, 3 중 하나로 선택할 때와 동일해진다.
따라서, dp[x] = dp[x - 1] + dp[x - 2] + dp[x - 3]
*/