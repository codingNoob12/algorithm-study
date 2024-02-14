#include <bits/stdc++.h>
using namespace std;

int n;
int t[16], p[16], d[16];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> t[i] >> p[i];

    for (int i = 0; i < n; i++) {
        if (i + t[i] > n)
            continue;
        int mx = 0;
        for (int j = 0; j < i; j++) {
            if (i - j >= t[j])
                mx = max(mx, d[j]);
        }
        d[i] = mx + p[i];
    }

    cout << *max_element(d, d + n);
}