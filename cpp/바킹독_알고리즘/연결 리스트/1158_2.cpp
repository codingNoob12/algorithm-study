#include <bits/stdc++.h>
using namespace std;

int N, K;
queue<int> Q;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> K;

    for (int i = 1; i <= N; i++) Q.push(i);

    cout << "<";
    int i = 1;
    while (!Q.empty()) {
        if (i == K) {
            cout << Q.front();
            if (Q.size() > 1) cout << ", ";
            Q.pop();
            i = 1;
        } else {
            Q.push(Q.front());
            Q.pop();
            i++;
        }
    }
    cout << ">";
}