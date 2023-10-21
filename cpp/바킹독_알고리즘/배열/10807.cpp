#include <bits/stdc++.h>
using namespace std;

int n, v, a[201], base = 100;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for (int i = 0; i < n; i++) {
    int t;
    cin >> t;
    a[t + base]++;
  }
  cin >> v;

  cout << a[v + base];
}