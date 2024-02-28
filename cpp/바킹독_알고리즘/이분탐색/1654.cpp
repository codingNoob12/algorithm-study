#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n, k;
int lengths[10'000];

bool solve(ll x) {
    ll cur = 0;
    for (int i = 0; i < k; i++)
        cur += lengths[i] / x;
    return cur >= n;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> k >> n;
    for (int i = 0; i < k; i++)
        cin >> lengths[i];

    ll st = 1, en = 0x7fffffff;
    while (st < en) {
        ll mid = (st + en + 1) / 2;
        if (solve(mid)) {
            st = mid;
        } else {
            en = mid - 1;
        }
    }
    cout << st;
}