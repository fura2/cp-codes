#include "template.hpp"

vector<pair<char, int>> run_length_encoding(const string& s) {
    vector<pair<char, int>> res;
    int n = s.length(), pre = 0;
    rep(i, n) if (i == n - 1 || s[i] != s[i + 1]) res.emplace_back(s[i], i - pre + 1), pre = i + 1;
    return res;
}

int main() {
    int n, d; cin >> n >> d;
    string s(d, 'o');
    rep(i, n) {
        string t; cin >> t;
        rep(j, d) if (t[j] == 'x') s[j] = 'x';
    }

    int ans = 0;
    for (auto [c, l] : run_length_encoding(s)) {
        if (c == 'o') chmax(ans, l);
    }
    cout << ans << endl;

    return 0;
}
