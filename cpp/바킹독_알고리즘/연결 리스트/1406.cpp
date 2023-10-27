#include <bits/stdc++.h>
using namespace std;

string s;
int m;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> s;
    list<char> editor(s.begin(), s.end());
    cin >> m;
    auto cursor = editor.end();
    for (int i = 0; i < m; i++) {
        char cmd, ch;
        cin >> cmd;
        if (cmd == 'P') {
            cin >> ch;
            editor.insert(cursor, ch);
        } else if (cmd == 'L') {
            if (cursor == editor.begin()) continue;
            cursor--;
        } else if (cmd == 'D') {
            if (cursor == editor.end()) continue;
            cursor++;
        } else {
            if (cursor == editor.begin()) continue;
            cursor = editor.erase(--cursor);
        }
    }
    for (auto i : editor) {
        cout << i;
    }
}