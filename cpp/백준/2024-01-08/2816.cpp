#include <bits/stdc++.h>
using namespace std;

int n, cur;
string channel_list[100];

int index_of(string channel) {
	auto it = find(channel_list, channel_list + n, channel);
	return distance(channel_list, it);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> channel_list[i];
	}

	string ans;

	int kbs1 = index_of("KBS1");
	if (kbs1 != 0) {
		while (cur != kbs1) {
			ans.append("1");
			cur++;
		}
		while (kbs1 != 0) {
			ans.append("4");
			swap(channel_list[cur], channel_list[cur - 1]);
			cur--;
			kbs1--;
		}
	}
	int kbs2 = index_of("KBS2");
	if (kbs2 != 1) {
		while (cur != kbs2) {
			ans.append("1");
			cur++;
		}
		while (kbs2 != 1) {
			ans.append("4");
			swap(channel_list[cur], channel_list[cur - 1]);
			cur--;
			kbs2--;
		}
	}

	cout << ans;
}