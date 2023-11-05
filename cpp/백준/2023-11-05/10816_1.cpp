#include <bits/stdc++.h>
using namespace std;

const int MX = 10000000;
int fre[2 * MX + 1];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m, x;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x;
        fre[x + MX]++;
    }
    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> x;
        cout << fre[x + MX] << " ";
    }
}