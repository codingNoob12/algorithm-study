#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;

  int freq[10] = {};
  while (n) {
    freq[n % 10]++;
    n /= 10;
  }

  freq[6] = (freq[6] + freq[9] + 1) / 2;
  cout << *max_element(freq, freq + 9);
}