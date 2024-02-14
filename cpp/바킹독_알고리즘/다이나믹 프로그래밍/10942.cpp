#include <bits/stdc++.h>
using namespace std;

int n, m, s, e, a[2001];
bool d[2001][2001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    for (int i = 1; i <= n; i++) {
        d[i][i] = 1;
        if (a[i - 1] == a[i])
            d[i - 1][i] = 1;
    }

    for (int gap = 2; gap < n; gap++) {
        for (int i = 1; i <= n - gap; i++) {
            int s = i, e = i + gap;
            if (d[s + 1][e - 1] && (a[s] == a[e]))
                d[s][e] = 1;
        }
    }

    cin >> m;
    while (m--) {
        cin >> s >> e;
        cout << d[s][e] << "\n";
    }
}