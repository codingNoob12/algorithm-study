#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    string str;
    cin >> str;
    stack<char> s;
    bool isValid = true;
    int sum = 0, num = 1;
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == '(' || str[i] == '[') {
            s.push(str[i]);

            if (str[i] == '(') num *= 2;
            else num *= 3;
        } else if (s.empty() ||
            ((s.top() != '(' || str[i] != ')') && (s.top() != '[' || str[i] != ']'))) {
            isValid = false;
            break;
        } else {
            s.pop();
            if (str[i - 1] == '(' || str[i - 1] == '[') sum += num;

            if (str[i] == ')') num /= 2;
            else num /= 3;
        }
    }

    if (!s.empty()) isValid = false;

    if (isValid) cout << sum;
    else cout << 0;
}
/*
 * 분배법칙을 떠올렸으면 쉽게 접근할 수 있는 풀이이다.
 *
 * a * (b + c) = a * b + a * c 이므로, 스택에 push할 때, 소괄호는 2, 대괄호는 3을 곱해가다가
 * pop을 할 때, 이전 괄호가 여는 괄호이면, 누적합을 해주면 된다.
 *
 * 그리고, 괄호를 닫으면 마찬가지로 소괄호는 2, 대괄호는 3을 나누어주면 된다.
 */