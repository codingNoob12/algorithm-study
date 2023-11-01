#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin >> s;
    stack<char> stk;
    long long cnt = 0;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '(') stk.push(s[i]);
        else {
            stk.pop();
            if (i - 1 >= 0 && s[i - 1] == '(') cnt += stk.size();
            else cnt++;
        }
    }
    cout << cnt;
}