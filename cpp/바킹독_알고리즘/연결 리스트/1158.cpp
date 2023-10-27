#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    list<int> seq;
    vector<int> res;
    for (int i = 1; i <= n; i++) {
        seq.push_back(i);
    }
    int i = 1;
    auto cur = seq.begin();
    while (!seq.empty()) {
        if (cur == seq.end()) cur = seq.begin();
        if (i % k == 0) {
            res.push_back(*cur);
            cur = seq.erase(cur);
        } else cur++;
        i++;
    }
    cout << "<";
    auto iter = res.begin();
    for (; iter != res.end() - 1; iter++) {
        cout << *iter << ", ";
    }
    cout << *iter << ">";
}