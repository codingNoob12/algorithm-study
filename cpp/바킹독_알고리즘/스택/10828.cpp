#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    stack<int> S;
    for (int i = 0; i < n; i++) {
        string op;
        cin >> op;
        if (op == "push") {
            int num;
            cin >> num;
            S.push(num);
        } else if (op == "pop") {
            if (S.empty()) cout << -1 << "\n";
            else {
                cout << S.top() << "\n";
                S.pop();
            }
        } else if (op == "size") {
            cout << S.size() << "\n";
        } else if (op == "empty") {
            cout << S.empty() << "\n";
        } else {
            if (S.empty()) cout << -1 << "\n";
            else cout << S.top() << "\n";
        }
    }
}