#include <bits/stdc++.h>
using namespace std;

#define AGE first
#define NAME second

int n;
pair<int, string> users[100'000], tmp[100'000];

void merge(int st, int en) {
    int mid = (st + en) / 2;
    int l = st, r = mid;
    for (int i = st; i < en; i++) {
        if (l == mid)
            tmp[i] = users[r++];
        else if (r == en)
            tmp[i] = users[l++];
        else if (users[l].AGE <= users[r].AGE)
            tmp[i] = users[l++];
        else
            tmp[i] = users[r++];
    }
    for (int i = st; i < en; i++)
        users[i] = tmp[i];
}

void merge_sort(int st, int en) {
    if (st + 1 >= en)
        return;
    int mid = (st + en) / 2;
    merge_sort(st, mid);
    merge_sort(mid, en);
    merge(st, en);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        int age;
        string name;
        cin >> age >> name;
        users[i] = {age, name};
    }

    merge_sort(0, n);

    for (int i = 0; i < n; i++)
        cout << users[i].AGE << " " << users[i].NAME << "\n";
}