#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, time, Y = 0, M = 0;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> time;
    Y += (time / 30 + 1) * 10;
    M += (time / 60 + 1) * 15;
  }
  if (Y == M) {
    cout << "Y M " << Y;
  } else if (Y > M) {
    cout << "M " << M;
  } else {
    cout << "Y " << Y;
  }
}