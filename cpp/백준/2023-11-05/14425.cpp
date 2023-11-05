#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m, cnt = 0;
    set < string > s;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        string str;
        cin >> str;
        s.insert(str);
    }
    for (int i = 0; i < m; i++) {
        string toCheck;
        cin >> toCheck;
        if (s.find(toCheck) != s.end()) cnt++;
    }
    cout << cnt;
}