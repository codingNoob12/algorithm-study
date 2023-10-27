#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int tc;
    cin >> tc;
    for (int i = 0; i < tc; i++) {
        string s;
        cin >> s;
        list<char> pw;
        auto cursor = pw.end();
        for (char ch : s) {
            if (ch == '<') {
                if (cursor != pw.begin()) cursor--;
            } else if (ch == '>') {
                if (cursor != pw.end()) cursor++;
            } else if (ch == '-') {
                if (cursor != pw.begin()) cursor = pw.erase(--cursor);
            } else pw.insert(cursor, ch);
        }

        for (char ch : pw) {
            cout << ch;
        }
        cout << "\n";
    }
}