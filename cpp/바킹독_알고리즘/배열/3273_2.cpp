#include <bits/stdc++.h>
using namespace std;

int a[100000];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, x;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  cin >> x;

  sort(a, a + n);
  int i = 0, j = n - 1, cnt = 0;
  while (i < j) {
    if (a[i] + a[j] == x) {
      cnt++;
      i++;
    } else if (a[i] + a[j] > x) {
      j--;
    } else {
      i++;
    }
  }
  cout << cnt;
}