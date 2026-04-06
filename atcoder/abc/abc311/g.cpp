#include "template.hpp"

lint f(const vector<vector<lint>>& A) {
    int h = A.size(), w = A[0].size();
    vector cum(h + 1, vector(w + 1, 0LL));
    rep(i, h) rep(j, w) cum[i + 1][j + 1] = cum[i + 1][j] + cum[i][j + 1] - cum[i][j] + A[i][j];

    lint res = 0;
    vector<int> t(w); // 高さ
    rep(i, h) {
        rep(j, w) {
            int lo = 0, hi = h - i + 1;
            while (hi - lo > 1) {
                int mi = (lo + hi) / 2;
                if (cum[i + mi][j + 1] - cum[i + mi][j] - cum[i][j + 1] + cum[i][j] >= 0) {
                    lo = mi;
                }
                else {
                    hi = mi;
                }
            }
            t[j] = lo;
        }

        stack<pair<int, int>> S; // (j, 高さ)
        S.emplace(-1, 0);
        rep(j, w) {
            int x = j;
            if (S.top().second > t[j]) {
                while (1) {
                    auto [pre, tall] = S.top();
                    chmax(res, cum[i + tall][j] - cum[i + tall][pre] - cum[i][j] + cum[i][pre]);
                    if (tall <= t[j]) break;
                    S.pop();
                    x = pre;
                }
            }
            if (S.top().second < t[j]) {
                S.emplace(x, t[j]);
            }
        }
        while (!S.empty()) {
            auto [pre, tall] = S.top();
            S.pop();
            chmax(res, cum[i + tall][w] - cum[i + tall][pre] - cum[i][w] + cum[i][pre]);
        }
    }
    return res;
}

int main() {
    int h, w; cin >> h >> w;
    vector A(h, vector(w, 0LL));
    rep(i, h) rep(j, w) cin >> A[i][j];

    vector B(h, vector(w, -(1LL << 29)));
    lint ans = 0;
    rrep(v, 1, 301) {
        rep(i, h) rep(j, w) if (A[i][j] == v) B[i][j] = v;
        chmax(ans, v * f(B));
    }
    cout << ans << endl;

    return 0;
}
