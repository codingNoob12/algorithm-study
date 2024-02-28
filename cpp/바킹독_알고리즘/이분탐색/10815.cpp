#include <bits/stdc++.h>
using namespace std;

int n, m;
int c[500'001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> c[i];
    sort(c, c + n);
    cin >> m;
    while (m--) {
        int x;
        cin >> x;
        cout << binary_search(c, c + n, x) << " ";
    }
}