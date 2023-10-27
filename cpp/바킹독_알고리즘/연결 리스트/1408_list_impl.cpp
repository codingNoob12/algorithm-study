#include <bits/stdc++.h>
using namespace std;

const int MX = 1000005;
char dat[MX];
int pre[MX], nxt[MX];
int unused = 1;

void insert(int addr, char ch) {
    dat[unused] = ch;
    pre[unused] = addr;
    nxt[unused] = nxt[addr];
    if (nxt[addr] != -1) pre[nxt[addr]] = unused;
    nxt[addr] = unused;
    unused++;
}

void erase(int addr) {
    if (nxt[addr] != -1) pre[nxt[addr]] = pre[addr];
    nxt[pre[addr]] = nxt[addr];
}

void traverse() {
    int cur = nxt[0];
    while (cur != -1) {
        cout << dat[cur];
        cur = nxt[cur];
    }
}

string s;
int m;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    fill(pre, pre + MX, -1);
    fill(nxt, nxt + MX, -1);

    cin >> s;
    int cursor = 0;
    for (char ch : s) insert(cursor++, ch);

    cin >> m;
    for (int i = 0; i < m; i++) {
        char cmd, ch;
        cin >> cmd;
        if (cmd == 'P') {
            cin >> ch;
            insert(cursor, ch);
            cursor = nxt[cursor];
        } else if (cmd == 'L') {
            if (pre[cursor] == -1) continue;
            cursor = pre[cursor];
        } else if (cmd == 'D') {
            if (nxt[cursor] == -1) continue;
            cursor = nxt[cursor];
        } else {
            if (cursor == 0) continue;
            int temp = pre[cursor];
            erase(cursor);
            cursor = temp;
        }
    }

    traverse();
}