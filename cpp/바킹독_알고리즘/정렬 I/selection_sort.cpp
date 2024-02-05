#include <bits/stdc++.h>
using namespace std;

int main() {
    int a[10] = {3, 2, 7, 116, 62, 235, 1, 23, 55, 77};
    int n = 10;
    for (int i = n - 1; i >= 0; i--) {
        int mx_idx = 0;
        for (int j = 1; j <= i; j++) {
            if (a[mx_idx] < a[j])
                mx_idx = j;
        }
        swap(a[mx_idx], a[i]);
    }

    for (auto e : a)
        cout << e << " ";
}