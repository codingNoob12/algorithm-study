#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    priority_queue<int> pq;
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        pq.push(-num);
    }

    int cnt = 0;
    while (pq.size() > 1) {
        int a, b;
        a = -pq.top();
        pq.pop();
        b = -pq.top();
        pq.pop();
        cnt += a + b;
        pq.push(-(a + b));
    }
    cout << cnt;
}