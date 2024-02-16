#include <bits/stdc++.h>
using namespace std;

int n, k;
int c[11];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> c[i];

    int i = n, ans = 0;
    while (k) {
        ans += k / c[i];
        k %= c[i--];
    }

    cout << ans;
}