#include <bits/stdc++.h>
using namespace std;

int n, ans;

bool isPrime(int x) {
    if (x <= 1)
        return 0;
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0)
            return 0;
    }
    return 1;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (isPrime(x))
            ans++;
    }

    cout << ans;
}