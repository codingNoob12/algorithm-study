#include <bits/stdc++.h>
using namespace std;

string S;
vector<string> suffix;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> S;
    for (int i = 0; i < S.length(); i++)
        suffix.push_back(S.substr(i, S.length()));

    sort(suffix.begin(), suffix.end());

    for (auto e : suffix)
        cout << e << "\n";
}