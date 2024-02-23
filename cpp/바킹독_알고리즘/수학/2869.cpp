#include <bits/stdc++.h>
using namespace std;

int a, b, v, d;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> a >> b >> v;
    d = ceil((double)(v - a) / (a - b)) + 1;
    cout << d;
}