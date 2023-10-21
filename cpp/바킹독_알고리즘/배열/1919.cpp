#include <bits/stdc++.h>
using namespace std;

string s[2];
int al[2][26];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> s[0] >> s[1];

  for (int i = 0; i < 2; i++)
    for (char c : s[i])
      al[i][c - 'a']++;

  int rm = 0;
  for (int i = 0; i < 26; i++) {
    if (al[0][i] != al[1][i])
      rm += max(al[0][i], al[1][i]) - min(al[0][i], al[1][i]);
  }

  cout << rm;
}