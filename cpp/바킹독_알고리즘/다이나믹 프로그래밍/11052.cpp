#include <bits/stdc++.h>
using namespace std;

int n;
int p[1001], d[1001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> p[i];

    for (int i = 1; i <= n; i++) {
        d[i] = p[i];
        for (int j = 1; j < i; j++)
            d[i] = max(d[i], p[i - j] + d[j]);
    }

    cout << d[n];
}