#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> votes(n);
    for (int i = 0; i < n; i++) cin >> votes[i];
    int cnt = 0;
    while (true) {
        int idx = 0;
        for (int i = 1; i < n; i++) {
            if (votes[idx] <= votes[i]) idx = i;
        }
        if (idx == 0) break;
        votes[0]++;
        votes[idx]--;
        cnt++;
    }

    cout << cnt;
}