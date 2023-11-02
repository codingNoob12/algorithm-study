#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m, num;
    cin >> n >> m;
    set<int> s;
    for (int i = 0; i < n; i++) {
        cin >> num;
        s.insert(num);
    }

    for (int i = 0; i < m; i++) {
        cin >> num;
        if (s.find(num) != s.end()) s.erase(num);
        else s.insert(num);
    }

    cout << s.size();
}