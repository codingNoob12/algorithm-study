#include <bits/stdc++.h>
using namespace std;

int n, m;
int a[100'001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a, a + n);

    cin >> m;
    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;

        int st = 0, en = n - 1;
        bool isExist = 0;
        while (st <= en) {
            int mid = (st + en) / 2;
            if (a[mid] == x) {
                isExist = 1;
                break;
            }
            if (a[mid] < x) {
                st = mid + 1;
            } else {
                en = mid - 1;
            }
        }
        cout << isExist << "\n";
    }
}