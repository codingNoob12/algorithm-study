#include <bits/stdc++.h>
using namespace std;

int n, ans;
vector<int> neg, pos;

void comb(vector<int> &v) {
    while (v.size() > 1) {
        ans += *(v.end() - 1) * *(v.end() - 2);
        v.pop_back();
        v.pop_back();
    }
    if (v.size()) {
        ans += v[0];
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (x == 1)
            ans++;
        else if (x > 0)
            pos.push_back(x);
        else
            neg.push_back(x);
    }

    sort(pos.begin(), pos.end());
    sort(neg.begin(), neg.end(), greater<>());
    comb(pos);
    comb(neg);

    cout << ans;
}