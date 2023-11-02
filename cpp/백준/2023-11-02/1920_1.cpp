#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, x, m;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];
    sort(nums.begin(), nums.end());

    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> x;
        cout << binary_search(nums.begin(), nums.end(), x) << "\n";
    }
}