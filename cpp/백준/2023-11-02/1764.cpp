#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    set < string > s;
    string name;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> name;
        s.insert(name);
    }

    set < string > ans;
    for (int i = 0; i < m; i++) {
        cin >> name;
        if (s.find(name) != s.end()) ans.insert(name);
    }
    cout << ans.size() << "\n";
    for (string e : ans) cout << e << "\n";
}