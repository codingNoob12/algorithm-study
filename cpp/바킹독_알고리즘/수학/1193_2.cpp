#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;

int x;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> x;

    int i = 1;
    while (x > i) {
        x -= i;
        i++;
    }

    int a = x, b = 1 + i - x;
    if (i % 2 == 1)
        swap(a, b);
    cout << a << "/" << b;
}