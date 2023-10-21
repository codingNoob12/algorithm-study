#include <bits/stdc++.h>
using namespace std;

int freq[10];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int a, b, c;
  cin >> a >> b >> c;
  int mul = a * b * c;
  while (mul) {
    freq[mul % 10]++;
    mul /= 10;
  }
  for (int e : freq) {
    cout << e << "\n";
  }
}