#include <bits/stdc++.h>
using namespace std;

int tc, n;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> tc;
    while (tc--) {
        cin >> n;
        vector<bool> state(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            for (int j = i; j <= n; j += i)
                state[j] = !state[j];
        }

        int ans = 0;
        for (int i = 1; i <= n; i++) {
            ans += state[i];
        }
        cout << ans << "\n";
    }
}