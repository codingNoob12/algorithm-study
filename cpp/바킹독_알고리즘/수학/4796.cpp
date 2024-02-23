#include <bits/stdc++.h>
using namespace std;

int l, p, v;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    for (int i = 1;; i++) {
        cin >> l >> p >> v;
        if (l == 0 && p == 0 && v == 0)
            break;
        cout << "Case " << i << ": " << (l * (v / p) + (v % p < l ? v % p : l)) << "\n";
    }
}