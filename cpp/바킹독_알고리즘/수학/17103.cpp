#include <bits/stdc++.h>
using namespace std;

const int MX = 1'000'000;

int tc;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    vector<bool> state(MX + 1, 1);
    state[1] = 0;
    for (int i = 2; i * i <= MX; i++) {
        if (!state[i])
            continue;
        for (int j = i * i; j <= MX; j += i)
            state[j] = 0;
    }

    cin >> tc;
    while (tc--) {
        int n, cnt = 0;
        cin >> n;
        for (int i = 2; i <= n / 2; i++) {
            if (state[i] && state[n - i])
                cnt++;
        }
        cout << cnt << "\n";
    }
}