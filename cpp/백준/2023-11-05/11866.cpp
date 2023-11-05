#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    queue<int> q;
    for (int i = 1; i <= n; i++) q.push(i);
    int i = 1;
    cout << "<";
    while (!q.empty()) {
        if (i % k == 0) {
            cout << q.front();
            q.pop();
            if (!q.empty()) cout << ", ";
        } else {
            q.push(q.front());
            q.pop();
        }
        i++;
    }
    cout << ">";
}