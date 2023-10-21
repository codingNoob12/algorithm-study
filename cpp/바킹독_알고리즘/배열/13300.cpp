#include <bits/stdc++.h>
using namespace std;

int n, k, s, y, cnt[7][2];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    cin >> s >> y;
    cnt[y][s]++;
  }

  int room = 0;
  for (int i = 1; i <= 6; i++) {
    for (int j = 0; j <= 1; j++) {
      if (cnt[i][j])
        room += (cnt[i][j] - 1) / k + 1;
    }
  }
  cout << room;
}