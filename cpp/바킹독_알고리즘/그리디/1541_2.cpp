#include <bits/stdc++.h>
using namespace std;

string expr;
int tmp, ans, sign = 1;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> expr;
    for (char c : expr) {
        if (c == '+' || c == '-') {
            ans += tmp * sign;
            if (c == '-')
                sign = -1;
            tmp = 0;
        } else {
            tmp *= 10;
            tmp += c - '0';
        }
    }
    ans += tmp * sign;
    cout << ans;
}