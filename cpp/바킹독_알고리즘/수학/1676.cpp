#include <bits/stdc++.h>
using namespace std;

int n, ans;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        int tmp = i;
        while (tmp % 5 == 0) {
            ans++;
            tmp /= 5;
        }
    }
    cout << ans;
}