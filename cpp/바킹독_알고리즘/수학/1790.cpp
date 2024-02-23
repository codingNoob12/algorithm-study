#include <bits/stdc++.h>
using namespace std;

int n, k;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        for (char c : to_string(i)) {
            if (++cnt == k) {
                cout << c;
                return 0;
            }
        }
    }
    cout << -1;
}