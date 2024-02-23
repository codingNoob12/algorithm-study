#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll solve(ll d) {
    return floor(2 * sqrt(d - 1e-9));
}

int tc;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> tc;
    while (tc--) {
        ll x, y;
        cin >> x >> y;
        cout << solve(y - x) << "\n";
    }
}