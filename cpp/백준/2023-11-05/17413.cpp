#include <bits/stdc++.h>
using namespace std;

void flush(stack<char> &s) {
    while (!s.empty()) {
        cout << s.top();
        s.pop();
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    string str;
    stack<char> s;
    getline(cin, str);
    int i = 0;
    while (i < str.length()) {
        if (str[i] == '<') {
            flush(s);
            size_t end = str.find('>', i);
            for (; i <= end && i < str.length(); i++) cout << str[i];
            i--;
        } else if (str[i] == ' ') {
            flush(s);
            cout << " ";
        } else s.push(str[i]);
        i++;
    }
    flush(s);
}