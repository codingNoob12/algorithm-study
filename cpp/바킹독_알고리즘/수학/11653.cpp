#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, i = 2;
    cin >> n;
    while (i <= n) {
        if (n % i == 0) {
            cout << i << "\n";
            n /= i;
        } else
            i++;
    }
}