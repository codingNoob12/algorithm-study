#include <bits/stdc++.h>
using namespace std;

int n, c;
int h[200'000];

int solve() {
    int st = 1, en = h[n - 1] - h[0];
    while (st < en) {
        int mid = (st + en + 1) / 2;

        int cnt = 1, pre = h[0];
        for (int i = 1; i < n; i++) {
            if (h[i] - pre >= mid) {
                pre = h[i];
                cnt++;
            }
        }

        if (cnt < c)
            en = mid - 1;
        else
            st = mid;
    }
    return st;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> c;
    for (int i = 0; i < n; i++)
        cin >> h[i];
    sort(h, h + n);

    cout << solve();
}