#include <bits/stdc++.h>
using namespace std;

int n;
int arr[1000], tmp[1000];

void merge(int st, int en) {
    int mid = (st + en) / 2;
    int l = st, r = mid;
    for (int i = st; i < en; i++) {
        if (l == mid)
            tmp[i] = arr[r++];
        else if (r == en)
            tmp[i] = arr[l++];
        else if (arr[l] <= arr[r]) // stable sort
            tmp[i] = arr[l++];
        else
            tmp[i] = arr[r++];
    }
    for (int i = st; i < en; i++)
        arr[i] = tmp[i];
}

void merge_sort(int st, int en) {
    if (st + 1 >= en)
        return;
    int mid = (st + en) / 2;
    merge_sort(st, mid);
    merge_sort(mid, en);
    merge(st, en);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    merge_sort(0, n);
    for (int i = 0; i < n; i++)
        cout << arr[i] << "\n";
}