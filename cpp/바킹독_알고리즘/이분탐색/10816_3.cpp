#include <bits/stdc++.h>
using namespace std;

int n, m;
int a[500'001];

int lowerBound(int x) {
    int st = 0, en = n;
    while (st < en) {
        int mid = (st + en) / 2;
        if (a[mid] >= x) {
            en = mid;
        } else {
            st = mid + 1;
        }
    }
    return st;
}

int upperBound(int x) {
    int st = 0, en = n;
    while (st < en) {
        int mid = (st + en) / 2;
        if (a[mid] > x) {
            en = mid;
        } else {
            st = mid + 1;
        }
    }
    return st;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a, a + n);

    cin >> m;
    while (m--) {
        int x;
        cin >> x;
        cout << upperBound(x) - lowerBound(x) << " ";
    }
}