#include <bits/stdc++.h>
using namespace std;

int a[9];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  for (int i = 0; i < 9; i++)
    cin >> a[i];

  int idx = 0;
  for (int i = 1; i < 9; i++) {
    if (a[idx] < a[i])
      idx = i;
  }
  cout << a[idx] << "\n" << idx + 1;
}