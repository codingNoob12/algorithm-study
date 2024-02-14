#include <bits/stdc++.h>
using namespace std;

int n, m;
int prefixSum[100'001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 1, x; i <= n; i++) {
        cin >> x;
        prefixSum[i] = prefixSum[i - 1] + x;
    }

    while (m--) {
        int i, j;
        cin >> i >> j;
        cout << prefixSum[j] - prefixSum[i - 1] << "\n";
    }
}