#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin >> s;
    stack<char> stk;
    stack<int> score;
    bool isValid = true;
    for (char ch : s) {
        if (ch == '(' || ch == '[') {
            stk.push(ch);
            score.push(-1);
        } else if (stk.empty() ||
            ((stk.top() != '(' || ch != ')') &&
                (stk.top() != '[' || ch != ']'))) {
            isValid = false;
            break;
        } else {
            stk.pop();

            int temp = 0;
            while (!score.empty() && score.top() >= 0) {
                temp += score.top();
                score.pop();
            }
            score.pop();

            if (temp) temp = (ch == ')') ? 2 * temp : 3 * temp;
            else temp = (ch == ')') ? 2 : 3;

            score.push(temp);
        }
    }

    if (!stk.empty()) isValid = false;

    int ans = 0;
    while (!score.empty()) {
        ans += score.top();
        score.pop();
    }

    if (isValid) cout << ans;
    else cout << 0;
}