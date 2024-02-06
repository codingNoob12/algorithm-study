#include <bits/stdc++.h>
using namespace std;

#define NUM first
#define FREQ second

int n, c;
vector<pair<int, int>> v;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> c;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        auto it = v.begin();
        for (; it != v.end(); it++) {
            if (it->NUM == x) {
                it->FREQ++;
                break;
            }
        }
        if (it == v.end())
            v.push_back({x, 1});
    }

    stable_sort(v.begin(), v.end(), [](const pair<int, int> &a, const pair<int, int> &b) {
        return a.FREQ > b.FREQ;
    });

    for (auto e : v) {
        for (int i = 0; i < e.FREQ; i++)
            cout << e.NUM << " ";
    }
}