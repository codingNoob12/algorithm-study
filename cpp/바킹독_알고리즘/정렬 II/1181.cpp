#include <bits/stdc++.h>
using namespace std;

int n;

bool cmp(const string &a, const string &b) {
    if (a.size() != b.size())
        return a.size() < b.size();
    return a < b;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    vector<string> v;
    for (int i = 0; i < n; i++) {
        string tmp;
        cin >> tmp;
        if (find(v.begin(), v.end(), tmp) != v.end())
            continue;
        v.push_back(tmp);
    }

    sort(v.begin(), v.end(), cmp);

    for (auto s : v)
        cout << s << "\n";
}