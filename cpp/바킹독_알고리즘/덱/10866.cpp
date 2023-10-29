#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    deque<int> DQ;
    while (n--) {
        string s;
        int x;
        cin >> s;
        if (s == "push_front") {
            cin >> x;
            DQ.push_front(x);
        } else if (s == "push_back") {
            cin >> x;
            DQ.push_back(x);
        } else if (s == "pop_front") {
            if (DQ.empty()) cout << -1 << "\n";
            else {
                cout << DQ.front() << "\n";
                DQ.pop_front();
            }
        } else if (s == "pop_back") {
            if (DQ.empty()) cout << -1 << "\n";
            else {
                cout << DQ.back() << "\n";
                DQ.pop_back();
            }
        } else if (s == "size") {
            cout << DQ.size() << "\n";
        } else if (s == "empty") {
            cout << DQ.empty() << "\n";
        } else if (s == "front") {
            if (DQ.empty()) cout << -1 << "\n";
            else cout << DQ.front() << "\n";
        } else {
            if (DQ.empty()) cout << -1 << "\n";
            else cout << DQ.back() << "\n";
        }
    }
}