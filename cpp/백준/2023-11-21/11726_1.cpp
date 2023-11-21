#include <bits/stdc++.h>

using namespace std;

int mem[1001][1001];

int combination(int n, int r) {
    if (r == 0 || n == r) mem[n][r] = 1;
    else if (!mem[n][r]) mem[n][r] = (combination(n - 1, r - 1) + combination(n - 1, r)) % 10007;
    return mem[n][r];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, ans = 0;
    cin >> n;
    for (int i = 0; 2 * i <= n; i++) ans = (ans + combination(n - i, i)) % 10007;
    cout << ans;
}