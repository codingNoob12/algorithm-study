#include <bits/stdc++.h>
using namespace std;

int n;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    int ans = 0;
    while (n >= 0) {
        if (n % 5 == 0) {
            ans += n / 5;
            cout << ans;
            return 0;
        }
        n -= 3;
        ans++;
    }

    cout << -1;
}