#include <bits/stdc++.h>
using namespace std;

int t, w;
int a[1001], d[1001][31];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> t >> w;
    for (int i = 1; i <= t; i++)
        cin >> a[i];

    d[1][0] = a[1] == 1, d[1][1] = a[1] == 2;
    for (int i = 2; i <= t; i++) {
        for (int j = 0; j <= w; j++) {
            if (j != 0)
                d[i][j] = max(d[i - 1][j - 1], d[i - 1][j]) + (a[i] == j % 2 + 1);
            else
                d[i][j] = d[i - 1][j] + (a[i] == j % 2 + 1);
        }
    }

    cout << *max_element(d[t], d[t] + w + 1);
}