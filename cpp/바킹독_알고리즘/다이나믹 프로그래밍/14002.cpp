#include <bits/stdc++.h>
using namespace std;

int n;
int a[1001], d[1001], nxt[1001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    fill(nxt, nxt + 1001, -1);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        d[i] = 1;
    }

    for (int i = n - 1; i >= 0; i--) {
        for (int j = 0; j < i; j++) {
            if (a[i] <= a[j])
                continue;
            if (d[i] + 1 > d[j]) {
                d[j] = d[i] + 1;
                nxt[j] = i;
            }
        }
    }

    int idx = distance(d, max_element(d, d + n));
    cout << d[idx] << "\n";
    while (idx != -1) {
        cout << a[idx] << " ";
        idx = nxt[idx];
    }
}