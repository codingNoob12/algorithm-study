#include <bits/stdc++.h>
using namespace std;

int n, cnt;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 1; i <= 10; i++) {
        vector<bool> flag(10);
        for (int j = 9; j >= 10 - i; j--)
            flag[j] = 1;
        do {
            if (cnt == n) {
                for (int j = 0; j < 10; j++) {
                    if (flag[j])
                        cout << 9 - j;
                }
                return 0;
            }
            cnt++;
        } while (next_permutation(flag.begin(), flag.end()));
    }
    cout << -1;
}