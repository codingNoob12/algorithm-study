#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n, m;
ll a[1000];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < m; i++) {
        swap(a[0], *min_element(a, a + n));
        swap(a[1], *min_element(a + 1, a + n));

        ll res = a[0] + a[1];
        a[0] = res, a[1] = res;
    }

    ll ans = 0;
    for (int i = 0; i < n; i++)
        ans += a[i];

    cout << ans;
}