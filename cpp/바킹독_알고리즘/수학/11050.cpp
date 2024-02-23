#include <bits/stdc++.h>
using namespace std;

int c(int n, int k) {
    if (k == 0 || n == k)
        return 1;
    return c(n - 1, k - 1) + c(n - 1, k);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;
    cout << c(n, k);
}