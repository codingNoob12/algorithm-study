#include <bits/stdc++.h>
using namespace std;

int n;
int d[100'001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    fill(d + 1, d + n + 1, 0x7f7f7f7f);
    for (int i = 1; i <= n; i++) {
        int si = int(sqrt(i));
        for (int j = 1; j <= si; j++) {
            d[i] = min(d[i], d[i - j * j] + 1);
        }
    }

    cout << d[n];
}