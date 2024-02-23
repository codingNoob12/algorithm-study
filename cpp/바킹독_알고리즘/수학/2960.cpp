#include <bits/stdc++.h>
using namespace std;

int n, k;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    vector<bool> state(n + 1, 1);

    int cnt = 0;
    for (int i = 2; i <= n; i++) {
        if (!state[i])
            continue;
        cnt++;
        if (cnt == k) {
            cout << i;
            break;
        }
        for (int j = i * 2; j <= n; j += i) {
            if (!state[j])
                continue;
            state[j] = 0;
            cnt++;
            if (cnt == k) {
                cout << j;
                return 0;
            }
        }
    }
}