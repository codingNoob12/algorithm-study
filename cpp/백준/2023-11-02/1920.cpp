#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, x, m;
    cin >> n;
    set<int> nums;
    for (int i = 0; i < n; i++) {
        cin >> x;
        nums.insert(x);
    }
    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> x;
        cout << (nums.find(x) != nums.end()) << "\n";
    }
}