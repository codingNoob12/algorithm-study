#include <bits/stdc++.h>
using namespace std;

int tc;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> tc;
    while (tc--) {
        int h, w, n;
        cin >> h >> w >> n;
        int i = (n - 1) % h + 1, j = (n - 1) / h + 1;
        cout << i;
        if (j < 10)
            cout << 0;
        cout << j << "\n";
    }
}