#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    while (true) {
        string s;
        getline(cin, s);
        if (s == ".") break;
        stack<char> stk;
        bool isValid = true;

        for (char ch : s) {
            if (ch == '(' || ch == '[') stk.push(ch);
            else if (ch == ')' || ch == ']') {
                if (stk.empty() ||
                    ((ch != ')' || stk.top() != '(') &&
                        (ch != ']' || stk.top() != '['))) {
                    isValid = false;
                    break;
                }
                stk.pop();
            }
        }

        if (!stk.empty()) isValid = false;

        if (isValid) cout << "yes\n";
        else cout << "no\n";
    }
}