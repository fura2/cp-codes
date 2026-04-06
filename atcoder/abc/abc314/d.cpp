#include "template.hpp"

int main() {
    int n;
    string s;
    int q;
    cin >> n >> s >> q;

    vector<tuple<int, int, char>> Q(q);
    rep(i, q) {
        int t, x;
        char c;
        cin >> t >> x >> c;
        x--;
        Q[i] = {t, x, c};
    }

    int last = -1;
    rep(i, q) {
        auto [t, x, c] = Q[i];
        if (t == 2 || t == 3)
            last = i;
    }
    rep(i, last) {
        auto [t, x, c] = Q[i];
        if (t == 1)
            s[x] = c;
    }
    if (last != -1) {
        auto [t, x, c] = Q[last];
        if (t == 2) {
            rep(i, n) s[i] = tolower(s[i]);
        } else if (t == 3) {
            rep(i, n) s[i] = toupper(s[i]);
        }
    }
    rep(i, last + 1, q) {
        auto [t, x, c] = Q[i];
        if (t == 1)
            s[x] = c;
    }

    cout << s << endl;

    return 0;
}
