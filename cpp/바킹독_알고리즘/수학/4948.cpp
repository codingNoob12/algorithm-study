#include <bits/stdc++.h>
using namespace std;

const int MX = 123456 * 2;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<bool> state(MX * 2 + 1, 1);
    state[1] = 0;
    for (int i = 2; i * i <= MX; i++) {
        if (!state[i])
            continue;
        for (int j = i * i; j <= MX; j += i) {
            state[j] = 0;
        }
    }

    while (1) {
        int n, cnt = 0;
        cin >> n;
        if (n == 0)
            break;
        for (int i = n + 1; i <= 2 * n; i++)
            if (state[i])
                cnt++;
        cout << cnt << "\n";
    }
}