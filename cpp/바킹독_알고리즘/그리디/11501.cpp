#include <bits/stdc++.h>
using namespace std;

int tc, n;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> tc;
    while (tc--) {
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        long long ans = 0;
        int mx = a[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            if (mx < a[i]) {
                mx = a[i];
            }
            ans += mx - a[i];
        }

        cout << ans << "\n";
    }
}