#include <bits/stdc++.h>
using namespace std;

int tc, n;
long long d[101] = {0, 1, 1, 1, 2, 2, 3, 4, 5};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    for (int i = 9, j = 12; i <= 100; i++, j += 2) {
        d[i] = d[i - 1] + d[j - (i - 1)];
    }

    cin >> tc;
    while (tc--) {
        cin >> n;
        cout << d[n] << "\n";
    }
}