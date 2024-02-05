#include <bits/stdc++.h>
using namespace std;

const int BASE = 10'000;

int n;
int counting[20'001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        counting[num + BASE]++;
    }

    for (int i = 0; i <= 2 * BASE; i++) {
        for (int j = 0; j < counting[i]; j++)
            cout << i - BASE << "\n";
    }
}