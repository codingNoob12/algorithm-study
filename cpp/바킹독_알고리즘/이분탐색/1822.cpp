#include <bits/stdc++.h>
using namespace std;

int na, nb;
int a[500'001], b[500'001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> na >> nb;
    for (int i = 0; i < na; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < nb; i++) {
        cin >> b[i];
    }

    sort(a, a + na);
    sort(b, b + nb);

    vector<int> diff;
    for (int i = 0; i < na; i++) {
        if (!binary_search(b, b + nb, a[i]))
            diff.push_back(a[i]);
    }
    cout << diff.size() << "\n";
    for (int i : diff)
        cout << i << " ";
}