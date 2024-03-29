#include <bits/stdc++.h>
using namespace std;

int n, m, ans = 0x7f7f7f7f;
int a[100'000];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a, a + n);
    int en = 0;
    for (int st = 0; st < n; st++) {
        while (en < n && a[en] - a[st] < m)
            en++;
        if (en == n)
            break;
        ans = min(ans, a[en] - a[st]);
    }
    cout << ans;
}