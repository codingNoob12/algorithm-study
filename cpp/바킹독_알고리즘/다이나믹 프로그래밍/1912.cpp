#include <bits/stdc++.h>
using namespace std;

int n, ans;
int d[100'001][2], a[100'001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    if (n == 1) {
        cout << a[1];
        return 0;
    }

    d[1][1] = a[1], d[2][0] = a[1], d[2][1] = max(d[1][1], 0) + a[2];
    for (int i = 3; i <= n; i++) {
        d[i][0] = max(d[i - 1][0], d[i - 1][1]);
        d[i][1] = max(0, d[i - 1][1]) + a[i];
    }

    cout << max(d[n][0], d[n][1]);
}