#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tc;
    cin >> tc;
    while (tc--) {
        string s;
        cin >> s;
        stack<char> stk;
        bool isValid = true;
        for (char ch : s) {
            if (ch == '(') stk.push(ch);
            else if (!stk.empty()) stk.pop();
            else {
                isValid = false;
                break;
            }
        }

        if (!stk.empty()) isValid = false;

        if (isValid) cout << "YES\n";
        else cout << "NO\n";
    }
}