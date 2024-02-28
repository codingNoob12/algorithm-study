#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int m, n;
int l[1'000'000];

bool solve(ll x) {
    ll cnt = 0;
    for (int i = 0; i < n; i++)
        cnt += l[i] / x;
    return cnt >= m;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> m >> n;
    for (int i = 0; i < n; i++)
        cin >> l[i];

    ll st = 1, en = *max_element(l, l + n);
    while (st < en) {
        ll mid = (st + en + 1) / 2;
        if (solve(mid)) {
            st = mid;
        } else {
            en = mid - 1;
        }
    }
    if (solve(st))
        cout << st;
    else
        cout << 0;
}