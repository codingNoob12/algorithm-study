#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  for (int i = 0; i < 3; i++) {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int temp[] = {a, b, c, d};
    int one = count(temp, temp + 4, 1);
    if (one == 1)
      cout << "C\n";
    else if (one == 2)
      cout << "B\n";
    else if (one == 3)
      cout << "A\n";
    else if (one == 4)
      cout << "E\n";
    else
      cout << "D\n";
  }
}