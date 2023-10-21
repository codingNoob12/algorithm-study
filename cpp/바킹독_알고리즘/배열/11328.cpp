#include <bits/stdc++.h>
using namespace std;

int n;
string s[2];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> s[0] >> s[1];

    int al[2][26] = {};
    for (int i = 0; i < 2; i++)
      for (char c : s[i])
        al[i][c - 'a']++;

    bool isPossible = true;
    for (int i = 0; i < 26; i++) {
      if (al[0][i] != al[1][i]) {
        isPossible = false;
        break;
      }
    }
    if (isPossible)
      cout << "Possible";
    else
      cout << "Impossible";
    cout << "\n";
  }
}