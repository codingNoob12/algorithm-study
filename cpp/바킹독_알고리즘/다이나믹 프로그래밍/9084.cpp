#include <bits/stdc++.h>
using namespace std;

int tc, n, m;
int c[21], d[10001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> tc;
    while (tc--) {
        fill(d, d + m + 1, 0);

        cin >> n;
        for (int i = 0; i < n; i++)
            cin >> c[i];
        cin >> m;

        d[0] = 1;
        for (int i = 0; i < n; i++) {
            for (int j = c[i]; j <= m; j++) {
                d[j] += d[j - c[i]];
            }
        }

        cout << d[m] << "\n";
    }
}