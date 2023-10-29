#include <bits/stdc++.h>
using namespace std;

const int MX = 10005;
int dat[2 * MX + 1];
int head = MX, tail = MX;

void push_front(int x) {
    dat[--head] = x;
}

void push_back(int x) {
    dat[tail++] = x;
}

void pop_front() {
    head++;
}

void pop_back() {
    tail--;
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
    while (n--) {
        string s;
        int x;
        cin >> s;
        if (s == "push_front") {
            cin >> x;
            push_front(x);
        } else if (s == "push_back") {
            cin >> x;
            push_back(x);
        } else if (s == "pop_front") {
            if (head == tail) cout << -1 << "\n";
            else {
                cout << front() << "\n";
                pop_front();
            }
        } else if (s == "pop_back") {
            if (head == tail) cout << -1 << "\n";
            else {
                cout << back() << "\n";
                pop_back();
            }
        } else if (s == "size") {
            cout << (tail - head) << "\n";
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