#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, cnt = 0;
    cin >> n;
    while (n--) {
        string s;
        cin >> s;
        stack<char> stk;
        for (char ch : s) {
            if (!stk.empty() && stk.top() == ch) stk.pop();
            else stk.push(ch);
        }
        if (stk.empty()) cnt++;
    }
    cout << cnt;
}