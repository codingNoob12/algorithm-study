#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m, x;
    map<int, int> M;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x;
        M[x]++;
    }
    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> x;
        if (M.find(x) != M.end()) cout << M[x] << " ";
        else cout << 0 << " ";
    }
}