#include <bits/stdc++.h>
using namespace std;

class Compare {
 public:
  bool operator()(int a, int b) {
	  if (abs(a) != abs(b)) return abs(a) > abs(b);
	  return a > b;
  }
};

priority_queue<int, vector<int>, Compare> pq;
int n, x;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	while (n--) {
		cin >> x;
		if (x) pq.push(x);
		else {
			if (pq.empty()) cout << 0 << "\n";
			else {
				cout << pq.top() << "\n";
				pq.pop();
			}
		}
	}
}