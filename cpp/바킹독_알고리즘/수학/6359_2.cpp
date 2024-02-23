#include <bits/stdc++.h>
using namespace std;

int tc, n;
bool state[101];
int ans[101];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    for (int i = 1; i <= 100; i++) {
        for (int j = i; j <= 100; j += i)
            state[j] = !state[j];
        for (int j = 1; j <= i; j++)
            ans[i] += state[j];
    }

    cin >> tc;
    while (tc--) {
        cin >> n;
        cout << ans[n] << "\n";
    }
}