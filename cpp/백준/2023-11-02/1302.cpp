#include <bits/stdc++.h>
using namespace std;

int n;
string s;
map<string, int> m;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s;
        if (m.find(s) != m.end()) m[s]++;
        else m[s] = 1;
    }

    auto mx = m.begin();
    for (auto iter = ++m.begin(); iter != m.end(); iter++) {
        if ((*mx).second < (*iter).second) mx = iter;
    }
    cout << (*mx).first;
}