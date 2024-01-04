#include <bits/stdc++.h>

using namespace std;

/**
 * 브루트포스 알고리즘
 * @details
 * <p style="color: white">특정 채널부터 +, - 버튼을 눌러서 목표 채널을 만들면 된다.</p>
 * <p>이 때의 채널 <b>channel</b>에서 부터 <u>+, - 버튼만으로</u> 목표 채널 <b>n</b>을 만들 때,</p>
 * <p>버튼을 누르는 횟수는 <b>abs(channel - n) + length(channel)<b></p>
 * <br>
 * <p style="color: red">그런데, 그 채널이 만들어질 수 있어야, 이후에 +, - 버튼만으로 목표 채널을 만들 수 있다.</p>
 * <p style="color:white">이는, 고장난 버튼이 해당 채널에 포함되어 있는지 확인하면 된다.</p>
 * <br>
 * <p style="color:white">이렇게, 모든 입력 가능한 채널로부터, 목표 채널을 만드는데 버튼을 눌러야 하는 횟수를 비교해가며, 최소값을 구하면 된다.</p>
 */

int n, m;
bool isBroken[10];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int btn;
        cin >> btn;
        isBroken[btn] = true;
    }

    int ans = abs(100 - n);

    for (int chanel = 0; chanel <= 1000000; chanel++) {
        bool isPossible = true;
        int e = 0;
        for (char ch : to_string(chanel)) {
            if (isBroken[ch - '0']) {
                isPossible = false;
                break;
            }
            e++;
        }
        if (isPossible) ans = min(ans, abs(chanel - n) + e);
    }

    cout << ans;
}
