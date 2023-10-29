#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    deque<int> DQ(n);
    for (int i = 1; i <= n; i++) DQ[i - 1] = i;

    int ans = 0;
    for (int i = 0; i < m; i++) {
        int val;
        cin >> val;
        int idx = find(DQ.begin(), DQ.end(), val) - DQ.begin();
        while (DQ.front() != val) {
            if (idx < (int) DQ.size() - idx) {
                DQ.push_back(DQ.front());
                DQ.pop_front();
            } else {
                DQ.push_front(DQ.back());
                DQ.pop_back();
            }
            ans++;
        }
        DQ.pop_front();
    }
    cout << ans;
}