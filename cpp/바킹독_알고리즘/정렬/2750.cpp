#include <bits/stdc++.h>
using namespace std;

int n;
int arr[1'000];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    sort(arr, arr + n);
    for (int i = 0; i < n; i++)
        cout << arr[i] << "\n";
}