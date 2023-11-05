#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    set < string > isExist;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string name, log;
        cin >> name >> log;
        if (log == "enter") isExist.insert(name);
        else isExist.erase(name);
    }
    vector<string> ans(isExist.begin(), isExist.end());
    sort(ans.begin(), ans.end(), [](string a, string b) { return a > b; });
    for (string name : ans) cout << name << "\n";
}