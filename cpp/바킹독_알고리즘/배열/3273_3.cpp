#include <bits/stdc++.h>
using namespace std;

int freq[2000001];
int n, x, cnt;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for (int i = 0; i < n; i++) {
    int temp;
    cin >> temp;
    freq[temp]++;
  }
  cin >> x;

  for (int i = (x + 1) / 2 - 1; i >= 0; i--) {
    if (freq[0 + i] && freq[x - i])
      cnt++;
  }
  cout << cnt;
}