#include <bits/stdc++.h>

using namespace std;

int prefix_sum[100000];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m, num;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> num;
        if (i > 0) prefix_sum[i] = prefix_sum[i - 1] + num;
        else prefix_sum[i] = num;
    }

    for (int x = 0; x < m; x++) {
        int i, j;
        cin >> i >> j;
        if (i > 1) cout << prefix_sum[j - 1] - prefix_sum[i - 2] << "\n";
        else cout << prefix_sum[j - 1] << "\n";
    }
}