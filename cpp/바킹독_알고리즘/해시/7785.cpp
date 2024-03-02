#include <bits/stdc++.h>
using namespace std;

int n;
unordered_set<string> s;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        string name, state;
        cin >> name >> state;
        if (state == "enter")
            s.insert(name);
        else
            s.erase(name);
    }

    vector<string> v(s.begin(), s.end());
    sort(v.begin(), v.end(), greater<>());
    for (auto e : v)
        cout << e << "\n";
}