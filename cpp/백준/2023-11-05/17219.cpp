#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    map<string, string> mp;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        string pw, site;
        cin >> pw >> site;
        mp[pw] = site;
    }
    for (int i = 0; i < m; i++) {
        string pw;
        cin >> pw;
        cout << mp[pw] << "\n";
    }
}