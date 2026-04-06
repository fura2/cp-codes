#include "template.hpp"

int main() {
    int n, t; cin >> n >> t;
    vector<int> c(n), r(n);
    rep(i, n) cin >> c[i];
    rep(i, n) cin >> r[i];

    int i_mx, mx = 0;
    rep(i, n) if (c[i] == t) {
        if (chmax(mx, r[i])) {
            i_mx = i;
        }
    }
    if (mx == 0) {
        rep(i, n) if (c[i] == c[0]) {
            if (chmax(mx, r[i])) {
                i_mx = i;
            }
        }
    }
    cout << i_mx + 1 << endl;

    return 0;
}
