#include <bits/stdc++.h>
#define X get<0>
#define Y get<1>
#define Z get<2>
using namespace std;
using ll = long long;

int n;
ll a[5000];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];

    sort(a, a + n);

    tuple<ll, ll, ll> ans = {0x7f7f7f7f, 0x7f7f7f7f, 0x7f7f7f7f};
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int l = lower_bound(a, a + n, -a[i] - a[j]) - a;
            int u = upper_bound(a, a + n, -a[i] - a[j]) - a;
            for (int k = l - 1; k <= u; k++) {
                if (k < 0 || k >= n || k == i || k == j)
                    continue;
                if (abs(X(ans) + Y(ans) + Z(ans)) > abs(a[i] + a[j] + a[k])) {
                    ans = {a[i], a[j], a[k]};
                }
            }
        }
    }

    ll sum = X(ans) + Y(ans) + Z(ans);
    ll mn = min({X(ans), Y(ans), Z(ans)}), mx = max({X(ans), Y(ans), Z(ans)}), md = sum - mn - mx;
    cout << mn << " " << md << " " << mx << "\n";
}