#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<string> names(n);
    map<string, int> name_map;
    for (int i = 0; i < n; i++) {
        cin >> names[i];
        name_map[names[i]] = i + 1;
    }

    for (int i = 0; i < m; i++) {
        string s;
        cin >> s;
        if (name_map.find(s) != name_map.end()) cout << name_map[s] << "\n";
        else cout << names[stoi(s) - 1] << "\n";
    }
}