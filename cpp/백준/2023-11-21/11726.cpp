#include <bits/stdc++.h>

using namespace std;

int cases[1001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, i;
    cin >> n;
    for (i = 1; i <= 2; i++) cases[i] = i;
    for (; i <= n; i++) cases[i] = (cases[i - 1] + cases[i - 2]) % 10007;
    cout << cases[n];
}