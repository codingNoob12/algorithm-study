#include <bits/stdc++.h>
using namespace std;

int n, m;
int a[100'000];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a, a + n);
    int ans = 0x7f7f7f7f;
    for (int i = 0; i < n; i++) {
        int idx = lower_bound(a, a + n, m + a[i]) - a;
        if (idx < n)
            ans = min(ans, abs(a[i] - a[idx]));
    }
    cout << ans;
}