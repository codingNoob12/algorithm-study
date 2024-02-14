#include <bits/stdc++.h>
using namespace std;

int n;
int d[1001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    d[1] = 1, d[2] = 2, d[3] = 1;
    for (int i = 4; i <= n; i++)
        d[i] = min(d[i - 1], d[i - 3]) + 1;
    cout << (d[n] % 2 == 1 ? "SK" : "CY");
}