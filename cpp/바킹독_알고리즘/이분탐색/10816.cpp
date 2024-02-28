#include <bits/stdc++.h>
using namespace std;

const int MX = 10'000'000;

int n, m;
int freq[2 * MX + 1];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        freq[x + MX]++;
    }

    cin >> m;
    while (m--) {
        int x;
        cin >> x;
        cout << freq[x + MX] << " ";
    }
}