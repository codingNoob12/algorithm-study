#include <bits/stdc++.h>
using namespace std;

#define S first
#define E second

int n;
pair<int, int> m[100'000];
stack<pair<int, int>> s;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        int s, e;
        cin >> s >> e;
        m[i] = {s, e};
    }

    sort(m, m + n);
    s.push(m[0]);
    for (int i = 1; i < n; i++) {
        if (s.top().E <= m[i].S)
            s.push(m[i]);
        else if (s.top().E >= m[i].E) {
            s.pop();
            s.push(m[i]);
        }
    }

    cout << s.size() << "\n";
}