#include "template.hpp"

vector<pair<char, int>> run_length_encoding(const string& s) {
    vector<pair<char, int>> res;
    int n = s.length(), pre = 0;
    rep(i, n) if (i == n - 1 || s[i] != s[i + 1]) res.emplace_back(s[i], i - pre + 1), pre = i + 1;
    return res;
}


int main() {
    int n;
    string s; cin >> n >> s;

    auto v = run_length_encoding(s);
    if (v.size() == 1) {
        cout << -1 << endl;
        return 0;
    }

    int mx = 0;
    for (auto [c, len] : v) if (c == 'o') chmax(mx, len);
    cout << mx << endl;

    return 0;
}
