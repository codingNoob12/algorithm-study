#include <bits/stdc++.h>
using namespace std;

pair<char, int> cards[5];

bool compare(pair<char, int> p1, pair<char, int> p2) {
	return p1.second < p2.second;
}

bool is_sequence() {
	for (int i = 0; i < 4; i++) {
		if (cards[i].second + 1 != cards[i + 1].second) return false;
	}
	return true;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	unordered_map<char, int> color_counter;
	unordered_map<int, int> number_counter;
	for (int i = 0; i < 5; i++) {
		char color;
		int num;
		cin >> color >> num;
		cards[i] = {color, num};
		
		if (color_counter.find(color) == color_counter.end())
			color_counter.insert({color, 1});
		else
			color_counter[color] += 1;

		if (number_counter.find(num) == number_counter.end())
			number_counter.insert({num, 1});
		else
			number_counter[num] += 1;
	}

	char c_max_col = color_counter.begin()->first;
	int c_max_cnt = color_counter.begin()->second;
	int n_max_num = number_counter.begin()->first;
	int n_max_cnt = number_counter.begin()->second;
	for (auto e : color_counter) {
		if (c_max_cnt < e.second) {
			c_max_col = e.first;
			c_max_cnt = e.second;
		}
	}

	for (auto e : number_counter) {
		if (n_max_cnt < e.second) {
			n_max_num = e.first;
			n_max_cnt = e.second;
		}
	}

	sort(cards, cards + 5, compare);

	int ans = 0;
	if (c_max_cnt == 5 && is_sequence()) {
		ans = 900 + cards[4].second;
	} else if (n_max_cnt == 4) {
		ans = 800 + n_max_num;
	} else if (n_max_cnt == 3 && number_counter.size() == 2) {
		ans = 700 + n_max_num * 10 + (cards[0].second != n_max_num ? cards[0].second : cards[4].second);
	} else if (c_max_cnt == 5) {
		ans = 600 + cards[4].second;
	} else if (is_sequence()) {
		ans = 500 + cards[4].second;
	} else if (n_max_cnt == 3) {
		ans = 400 + n_max_num;
	} else if (n_max_cnt == 2 && number_counter.size() == 3) {
		ans = 300 + cards[3].second * 10 + cards[1].second;
	} else if (n_max_cnt == 2) {
		ans = 200 + n_max_num;
	} else {
		ans = 100 + cards[4].second;
	}

	cout << ans;
}