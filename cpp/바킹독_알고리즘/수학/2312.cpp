#include <bits/stdc++.h>
using namespace std;

int tc;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> tc;
    while (tc--) {
        int n, i = 2, cnt = 0;
        cin >> n;
        while (i <= n) {
            if (n % i == 0) {
                cnt++;
                n /= i;
            } else {
                if (cnt)
                    cout << i << " " << cnt << "\n";
                i++;
                cnt = 0;
            }
        }
        cout << i << " " << cnt << "\n";
    }
}