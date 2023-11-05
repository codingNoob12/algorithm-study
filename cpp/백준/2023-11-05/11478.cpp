#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    set < string > s;
    string str;
    cin >> str;
    for (int i = 0; i < str.length(); i++) {
        string sub;
        for (int j = i; j < str.length(); j++) {
            sub += str[j];
            s.insert(sub);
        }
    }
    cout << s.size();
}