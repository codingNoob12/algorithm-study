#include <bits/stdc++.h>
using namespace std;

int n;
int w[10001], d[10001][3];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> w[i];

    d[1][1] = w[1];
    for (int i = 2; i <= n; i++) {
        d[i][0] = max({d[i - 1][0], d[i - 1][1], d[i - 1][2]});
        d[i][1] = d[i - 1][0] + w[i];
        d[i][2] = d[i - 1][1] + w[i];
    }

    cout << *max_element(d[n], d[n] + 3);
}