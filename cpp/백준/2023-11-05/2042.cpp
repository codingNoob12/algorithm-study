#include <bits/stdc++.h>
using namespace std;

const int MX = 1000001;
long long nums[MX], st[MX * 4];

long long init(int start, int end, int node) {
    if (start == end) return st[node] = nums[start];
    int mid = (start + end) / 2;
    return st[node] = init(start, mid, node * 2) +
        init(mid + 1, end, node * 2 + 1);
}

long long sum(int start, int end, int node, int left, int right) {
    if (left > end || right < start) return 0;
    if (start >= left && end <= right) return st[node];
    int mid = (start + end) / 2;
    return sum(start, mid, node * 2, left, right) +
        sum(mid + 1, end, node * 2 + 1, left, right);
}

void update(int start, int end, int node, int target, long long diff) {
    if (target < start || target > end) return;
    st[node] += diff;
    if (start == end) return;
    int mid = (start + end) / 2;
    update(start, mid, node * 2, target, diff);
    update(mid + 1, end, node * 2 + 1, target, diff);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m, k, a, b;
    long long c;
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++) cin >> nums[i];
    init(0, n - 1, 1);
    for (int i = 0; i < m + k; i++) {
        cin >> a >> b >> c;
        if (a == 1) {
            long long diff = c - nums[b - 1];
            nums[b - 1] = c;
            update(0, n - 1, 1, b - 1, diff);
        } else cout << sum(0, n - 1, 1, b - 1, c - 1) << "\n";
    }
}