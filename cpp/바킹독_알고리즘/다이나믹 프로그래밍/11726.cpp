#include <bits/stdc++.h>
using namespace std;

int n, d[1001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    d[1] = 1, d[2] = 2;
    for (int i = 3; i <= n; i++)
        d[i] = (d[i - 1] + d[i - 2]) % 10007;

    cout << d[n];
}
/*
d[n] = [1x2 + 2x(n-1)] + [2x1 * 2 + 2x(n-2)] => d[n - 1] + d[n - 2]
*/