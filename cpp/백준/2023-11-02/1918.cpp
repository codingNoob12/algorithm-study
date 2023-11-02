#include <bits/stdc++.h>
using namespace std;

int getPriority(char ch) {
    if (ch == '+' || ch == '-') return 1;
    if (ch == '*' || ch == '/') return 2;
    return -1;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    stack<char> s;
    string str;
    cin >> str;
    for (char ch : str) {
        if (isalpha(ch)) cout << ch;
        else {
            if (ch == ')') {
                while (!s.empty() && s.top() != '(') {
                    cout << s.top();
                    s.pop();
                }
                s.pop();
            } else {
                while (ch != '(' && !s.empty() && getPriority(s.top()) >= getPriority(ch)) {
                    cout << s.top();
                    s.pop();
                }

                s.push(ch);
            }
        }
    }

    while (!s.empty()) {
        cout << s.top();
        s.pop();
    }
}