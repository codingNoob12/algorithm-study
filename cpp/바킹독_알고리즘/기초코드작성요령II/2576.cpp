#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int min = 100, n, sum = 0;
  for (int i = 0; i < 7; i++) {
    cin >> n;
    if (n % 2 == 1) {
      sum += n;
      min = min > n ? n : min;
    }
  }
  if (min == 100) {
    cout << -1;
  } else {
    cout << sum << "\n" << min;
  }
}