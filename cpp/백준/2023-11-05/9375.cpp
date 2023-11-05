#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tc, n;
    cin >> tc;
    for (int i = 0; i < tc; i++) {
        cin >> n;
        map<string, int> counts;
        for (int j = 0; j < n; j++) {
            string name, cat;
            cin >> name >> cat;
            counts[cat]++;
        }
        int ans = 1;
        for (auto e : counts) ans *= (e.second + 1);
        ans--;
        cout << ans << "\n";
    }
}