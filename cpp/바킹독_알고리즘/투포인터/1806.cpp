#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n, s;
int a[100'000];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> s;
    for (int i = 0; i < n; i++)
        cin >> a[i];

    ll sum = a[0];
    int ans = 0x7f7f7f7f, en = 0;
    for (int st = 0; st < n; st++) {
        while (en < n && sum < s) {
            en++;
            if (en != n)
                sum += a[en];
        }
        if (en == n)
            break;
        ans = min(ans, en - st + 1);
        sum -= a[st];
    }

    if (ans == 0x7f7f7f7f)
        ans = 0;
    cout << ans;
}