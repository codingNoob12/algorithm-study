#include <bits/stdc++.h>
using namespace std;

int tc, n;
long long d[101] = {0, 1, 1};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    for (int i = 3; i <= 100; i++)
        d[i] = d[i - 2] + d[i - 3];

    cin >> tc;
    while (tc--) {
        cin >> n;
        cout << d[n] << "\n";
    }
}