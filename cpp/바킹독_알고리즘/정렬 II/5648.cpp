#include <bits/stdc++.h>
using namespace std;

int n;
vector<long long> res;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        string tmp;
        cin >> tmp;
        reverse(tmp.begin(), tmp.end());
        res.push_back(stoll(tmp));
    }

    sort(res.begin(), res.end());

    for (auto e : res)
        cout << e << "\n";
}