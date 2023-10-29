#include <bits/stdc++.h>
using namespace std;

void parse(deque<int> &nums) {
    string temp;
    cin >> temp;
    temp = regex_replace(temp, regex("[\\[\\]]"), "");

    istringstream iss(temp);
    string buffer;
    while (getline(iss, buffer, ',')) nums.push_back(stoi(buffer));
}

void print_result(deque<int> &nums) {
    cout << "[";
    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i];
        if (i + 1 != nums.size()) cout << ",";
    }
    cout << "]\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tc;
    cin >> tc;
    while (tc--) {
        string p, temp;
        int n;
        deque<int> nums;
        bool isReversed = false, isError = false;
        cin >> p;
        cin >> n;
        parse(nums);

        for (char f : p) {
            if (isError) break;
            if (f == 'R') isReversed = !isReversed;
            else {
                if (nums.empty()) isError = true;
                else {
                    if (isReversed) nums.pop_back();
                    else nums.pop_front();
                }
            }
        }

        if (isError) {
            cout << "error\n";
            continue;
        }

        if (isReversed) reverse(nums.begin(), nums.end());

        print_result(nums);
    }
}