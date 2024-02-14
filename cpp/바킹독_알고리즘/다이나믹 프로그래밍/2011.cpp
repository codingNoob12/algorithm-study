#include <bits/stdc++.h>
using namespace std;

string s;
int a[5001], d[5001], n, mod = 1000000;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> s;
    n = s.length();

    for (int i = 1; i <= n; i++)
        a[i] = s[i - 1] - '0';

    d[0] = 1;
    for (int i = 1; i <= n; i++) {
        if (a[i])
            d[i] = (d[i] + d[i - 1]) % mod;
        int x = a[i - 1] * 10 + a[i];
        if (x >= 10 && x <= 26)
            d[i] = (d[i] + d[i - 2]) % mod;
    }

    cout << d[n];
}