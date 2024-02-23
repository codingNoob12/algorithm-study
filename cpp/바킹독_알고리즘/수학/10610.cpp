#include <bits/stdc++.h>
using namespace std;

string n;
vector<int> v;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (auto c : n) {
        v.push_back(c - '0');
    }

    sort(v.begin(), v.end(), greater<>());

    int sum = 0;
    for (auto e : v)
        sum += e;
    if (sum % 3 == 0 && v.back() == 0) {
        for (auto e : v)
            cout << e;
    } else
        cout << -1;
}