#include <bits/stdc++.h>
using namespace std;

const int BASE = 1'000'000;

int n;
int freq[2 * BASE + 1];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        freq[x + BASE]++;
    }

    for (int i = 0; i <= 2 * BASE; i++) {
        while (freq[i]--)
            cout << i - BASE << "\n";
    }
}