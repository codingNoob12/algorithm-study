#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;

int n;
vector<pair<int, int>> f;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        int sm, sd, em, ed;
        cin >> sm >> sd >> em >> ed;
        f.push_back({sm * 100 + sd, em * 100 + ed});
    }

    int t = 301, ans = 0;
    while (t < 1201) {
        int nt = t;
        for (int i = 0; i < n; i++) {
            if (f[i].X <= t && f[i].Y > nt)
                nt = f[i].Y;
        }
        if (nt == t) {
            cout << 0;
            return 0;
        }
        t = nt;
        ans++;
    }
    cout << ans;
}