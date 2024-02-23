#include <bits/stdc++.h>
using namespace std;

int a, b;
int seqSum(int x) {
    int i = 1, sum = 0;
    while (x > i)
        sum += i * i, x -= i++;
    return sum + i * x;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> a >> b;
    cout << seqSum(b) - seqSum(a - 1);
}