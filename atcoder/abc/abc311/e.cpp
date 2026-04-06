#include "template.hpp"

int main() {
    int h, w, n; cin >> h >> w >> n;
    vector cum(h + 1, vector(w + 1, 0));
    rep(i, n) {
        int a, b; cin >> a >> b; a--; b--;
        cum[a + 1][b + 1]++;
    }
    rep(i, h) rep(j, w) cum[i + 1][j + 1] += cum[i + 1][j] + cum[i][j + 1] - cum[i][j];

    lint ans = 0;
    rep(i, h) rep(j, w) {
        int lo = 0, hi = min(h - i, w - j) + 1;
        while (hi - lo > 1) {
            int mi = (lo + hi) / 2;
            if (cum[i + mi][j + mi] - cum[i + mi][j] - cum[i][j + mi] + cum[i][j] == 0) lo = mi;
            else hi = mi;
        }
        ans += lo;
    }
    cout << ans << endl;

    return 0;
}
