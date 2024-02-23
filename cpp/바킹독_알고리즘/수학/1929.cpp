#include <bits/stdc++.h>
using namespace std;

const int N = 1'000'000;
vector<bool> state(N + 1, 1);

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    state[1] = 0;
    for (int i = 2; i * i <= N; i++) {
        if (!state[i])
            continue;
        for (int j = i * i; j <= N; j += i)
            state[j] = 0;
    }

    int m, n;
    cin >> m >> n;
    for (int i = m; i <= n; i++) {
        if (state[i])
            cout << i << "\n";
    }
}