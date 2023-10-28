#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> nums(n);
    vector<int> ans(n);
    for (int i = 0; i < n; i++) cin >> nums[i];

    stack<int> S;
    for (int i = n - 1; i >= 0; i--) {
        while (!S.empty() && S.top() <= nums[i]) S.pop();
        if (S.empty()) ans[i] = -1;
        else ans[i] = S.top();
        S.push(nums[i]);
    }

    for (int e : ans) {
        cout << e << " ";
    }
}