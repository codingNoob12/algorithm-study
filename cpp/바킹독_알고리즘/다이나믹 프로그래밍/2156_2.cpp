#include <bits/stdc++.h>
using namespace std;

int n;
int w[10001], d[10001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> w[i];

    d[1] = w[1], d[2] = d[1] + w[2];
    for (int i = 2; i <= n; i++)
        d[i] = max({d[i - 3] + w[i - 1] + w[i], d[i - 2] + w[i], d[i - 1]});

    cout << d[n];
}