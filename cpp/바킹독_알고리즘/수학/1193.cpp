#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;

int x;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> x;
    int i = 1, sum = 0;
    while (sum < x) {
        sum += i++;
    }

    int a, b;
    pair<int, int> d;
    if (i % 2 == 0) {
        a = 1, b = i - 1;
        d = {1, -1};
    } else {
        a = i - 1, b = 1;
        d = {-1, 1};
    }

    while (sum != x) {
        a += d.X, b += d.Y;
        sum--;
    }

    cout << a << "/" << b;
}