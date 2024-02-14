#include <bits/stdc++.h>
using namespace std;

int n;
int tr[500][500];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++)
            cin >> tr[i][j];
    }

    for (int i = 1; i < n; i++) {
        tr[i][0] += tr[i - 1][0];
        tr[i][i] += tr[i - 1][i - 1];
        for (int j = 1; j < i; j++)
            tr[i][j] = max(tr[i - 1][j - 1], tr[i - 1][j]) + tr[i][j];
    }
    cout << *max_element(tr[n - 1], tr[n - 1] + n);
}