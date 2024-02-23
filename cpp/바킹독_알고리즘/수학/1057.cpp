#include <bits/stdc++.h>
using namespace std;

int n, a, b;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> a >> b;
    for (int i = 1;; i++) {
        if (a % 2)
            a++;
        a /= 2;
        if (b % 2)
            b++;
        b /= 2;
        if (a == b) {
            cout << i;
            return 0;
        }
    }
    cout << -1;
}