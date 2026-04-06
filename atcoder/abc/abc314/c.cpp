#include "template.hpp"

int main() {
    int n, m;
    string s;
    cin >> n >> m >> s;
    vector<int> color(n);
    rep(i, n) cin >> color[i], color[i]--;

    vector<vector<int>> pos(m);
    rep(i, n) pos[color[i]].emplace_back(i);

    string ans = s;
    rep(c, m) rep(i, ssize(pos[c])) ans[pos[c][(i + 1) % size(pos[c])]] = s[pos[c][i]];
    cout << ans << endl;

    return 0;
}
