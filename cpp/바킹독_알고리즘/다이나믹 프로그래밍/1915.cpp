#include <bits/stdc++.h>
using namespace std;

int n, m, sz;
int b[1001][1001], d[1001][1001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        string buf;
        cin >> buf;
        for (int j = 1; j <= m; j++)
            b[i][j] = buf[j - 1] - '0';
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (b[i][j]) {
                d[i][j] = min({d[i - 1][j - 1], d[i - 1][j], d[i][j - 1]}) + 1;
                sz = max(sz, d[i][j]);
            }
        }
    }

    cout << sz * sz;
}