#include <bits/stdc++.h>
using namespace std;

int n;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = n / 5; i >= 0; i--) {
        int rest = n - 5 * i;
        if (rest % 3 == 0) {
            cout << i + rest / 3;
            return 0;
        }
    }
    cout << -1;
}