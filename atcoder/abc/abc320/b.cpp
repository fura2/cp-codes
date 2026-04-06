#include "template.hpp"

int main() {
    string s;
    cin >> s;
    int n = size(s);

    int ans = 1;
    rep (i, n) {
        rep (j, i + 1, n + 1) {
            string t = s.substr(i, j - i);
            string u = t;
            reverse(all(u));
            if (t == u) chmax(ans, j - i);
        }
    }
    cout << ans << endl;

    return 0;
}
