#include <bits/stdc++.h>
using namespace std;

int main() {
    int a[5] = {2, 13, 6, 4, -2};
    int n = 5;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (a[j] > a[j + 1])
                swap(a[j], a[j + 1]);
        }
    }

    for (auto e : a)
        cout << e << " ";
}