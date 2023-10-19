#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int tall[9];
  for (int i = 0; i < 9; i++) {
    cin >> tall[i];
  }
  sort(tall, tall + 9);
  int tot = 0;
  for (int i = 0; i < 9; i++) {
    tot += tall[i];
  }
  for (int i = 0; i < 9; i++) {
    for (int j = i + 1; j < 9; j++) {
      if (tot - tall[i] - tall[j] == 100) {
        for (int idx = 0; idx < 9; idx++) {
          if (idx == i || idx == j)
            continue;
          cout << tall[idx] << "\n";
        }
        return 0;
      }
    }
  }
}