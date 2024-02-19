#include <bits/stdc++.h>
using namespace std;

string expr;

vector<string> split(string &str, const string &delim) {
    vector<string> ret;
    long long pos = 0;
    string token = "";
    while ((pos = str.find(delim)) != string::npos) {
        token = str.substr(0, pos);
        ret.push_back(token);
        str.erase(0, pos + 1);
    }
    ret.push_back(str);
    return ret;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> expr;

    int ans = 0;
    vector<string> exprs = split(expr, "-");
    for (int i = 0; i < exprs.size(); i++) {
        int tmp = 0;
        for (auto e : split(exprs[i], "+")) {
            tmp += stoi(e);
        }
        if (i == 0)
            ans += tmp;
        else
            ans -= tmp;
    }

    cout << ans;
}