#include <bits/stdc++.h>
using namespace std;

const int MX = 5001;
int pre[MX], nxt[MX];

void erase(int i) {
    if (nxt[i] != -1) pre[nxt[i]] = pre[i];
    nxt[pre[i]] = nxt[i];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, K;
    cin >> N >> K;
    for (int i = 1; i <= N; i++) {
        pre[i] = (i == 1) ? N : i - 1;
        nxt[i] = (i == N) ? 1 : i + 1;
    }

    cout << "<";
    int i = 1;
    for (int cur = 1; N > 0; cur = nxt[cur]) {
        if (i == K) {
            erase(cur);
            cout << cur;
            if (N != 1) cout << ", ";
            i = 1;
            N--;
        } else i++;
    }
    cout << ">";
}