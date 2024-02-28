#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n, m;
int h[1'000'000];

bool solve(int x) {
    ll tot = 0;
    for (int i = 0; i < n; i++) {
        if (h[i] >= x)
            tot += h[i] - x;
    }
    return tot >= m;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> h[i];

    ll st = 0, en = *max_element(h, h + n);
    while (st < en) {
        ll mid = (st + en + 1) / 2;
        if (solve(mid))
            st = mid;
        else
            en = mid - 1;
    }
    cout << st;
}