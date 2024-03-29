#include <bits/stdc++.h>
using namespace std;

const int MX = 100005;
int dat[MX];
int head, tail;

void push(int x) {
    dat[tail++] = x;
}

void pop() {
    head++;
}

int front() {
    return dat[head];
}

int back() {
    return dat[tail - 1];
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
            int x;
            cin >> x;
            push(x);
        } else if (s == "pop") {
            if (head == tail) cout << -1 << "\n";
            else {
                cout << front() << "\n";
                pop();
            }
        } else if (s == "size") {
            cout << tail - head << "\n";
        } else if (s == "empty") {
            cout << (head == tail) << "\n";
        } else if (s == "front") {
            if (head == tail) cout << -1 << "\n";
            else cout << front() << "\n";
        } else {
            if (head == tail) cout << -1 << "\n";
            else cout << back() << "\n";
        }
    }
}