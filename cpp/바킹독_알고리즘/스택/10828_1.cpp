#include <bits/stdc++.h>
using namespace std;

const int MX = 10001;
int dat[MX];
int pos;

void push(int num) {
    dat[pos++] = num;
}

void pop() {
    pos--;
}

int top() {
    return dat[pos - 1];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        if (s == "push") {
            int num;
            cin >> num;
            push(num);
        } else if (s == "pop") {
            if (pos == 0) cout << -1 << "\n";
            else {
                cout << top() << "\n";
                pop();
            }
        } else if (s == "size") {
            cout << pos << "\n";
        } else if (s == "empty") {
            cout << (pos == 0) << "\n";
        } else {
            if (pos == 0) cout << -1 << "\n";
            else cout << top() << "\n";
        }
    }
}