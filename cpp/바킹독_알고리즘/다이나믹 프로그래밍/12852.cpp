#include <bits/stdc++.h>
using namespace std;

int n;
int d[1'000'001], pre[1'000'001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 2; i <= n; i++) {
        d[i] = d[i - 1] + 1;
        pre[i] = i - 1;
        if (i % 2 == 0 && d[i / 2] + 1 < d[i]) {
            d[i] = d[i / 2] + 1;
            pre[i] = i / 2;
        }
        if (i % 3 == 0 && d[i / 3] + 1 < d[i]) {
            d[i] = d[i / 3] + 1;
            pre[i] = i / 3;
        }
    }

    cout << d[n] << "\n";
    int x = n;
    while (1) {
        cout << x << " ";
        if (x == 1)
            break;
        x = pre[x];
    }
}