#include <bits/stdc++.h>
using namespace std;

int tc, n;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> tc;
    while (tc--) {
        int d[41] = {};
        cin >> n;
        d[n] = 1;
        for (int i = n; i > 1; i--) {
            d[i - 1] += d[i];
            d[i - 2] += d[i];
        }
        cout << d[0] << " " << d[1] << "\n";
    }
}