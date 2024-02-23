#include <bits/stdc++.h>
using namespace std;

int a, b;
int arr[1001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int cnt = 0;
    for (int i = 1, j = 1; i <= 1000; i++) {
        arr[i] = j;
        cnt++;
        if (cnt == j) {
            cnt = 0;
            j++;
        }
    }

    cin >> a >> b;
    int sum = 0;
    for (int i = a; i <= b; i++) {
        sum += arr[i];
    }
    cout << sum;
}