#include <bits/stdc++.h>
using namespace std;

int n, k, w[101], v[101];
int d[101][100'001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> w[i] >> v[i];

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= k; j++) {
            if (j - w[i] >= 0)
                d[i][j] = max(d[i - 1][j], d[i - 1][j - w[i]] + v[i]);
            else
                d[i][j] = d[i - 1][j];
        }
    }

    cout << d[n][k];
}