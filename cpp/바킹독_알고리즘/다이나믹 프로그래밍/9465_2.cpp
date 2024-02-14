#include <bits/stdc++.h>
using namespace std;

int tc, n;
int s[2][100'001], d[2][100'001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> tc;
    while (tc--) {
        cin >> n;
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < n; j++)
                cin >> s[i][j];
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 2; j++) {
                int mx = 0;
                if (i > 1)
                    mx = max(d[0][i - 2], d[1][i - 2]);
                if (i > 0)
                    mx = max(mx, d[1 - j][i - 1]);
                d[j][i] = mx + s[j][i];
            }
        }
        cout << max(d[0][n - 1], d[1][n - 1]) << "\n";
    }
}