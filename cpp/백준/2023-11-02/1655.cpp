#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;

    priority_queue<int> smalls, larges;
    int middle = INT_MAX;

    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;

        if (middle == INT_MAX) {
            middle = num;
            smalls.push(num);
        } else if (middle < num) larges.push(-num);
        else smalls.push(num);

        if (larges.size() > smalls.size()) {
            smalls.push(-larges.top());
            larges.pop();
        } else if (larges.size() < smalls.size() - 1) {
            larges.push(-smalls.top());
            smalls.pop();
        }
        
        middle = smalls.top();
        cout << middle << "\n";
    }
}