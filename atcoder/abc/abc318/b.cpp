#include "template.hpp"

int main() {
    int n;
    cin >> n;

    bool B[100][100] = {};
    rep (i, n) {
        int l, r, t, b;
        cin >> l >> r >> t >> b;
        rep (x, t, b)
            rep (y, l, r) B[x][y] = true;
    }

    int ans = 0;
    rep (i, 100)
        rep (j, 100) ans += B[i][j];
    cout << ans << endl;

    return 0;
}
