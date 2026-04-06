#include "template.hpp"

const lint INF = 1LL << 61;

int h, w;
lint A[6][6], cum[7][7];

// [t, b) x [l, r) を k 回分割して, 各パーツの重みの和が ub 以下になるようにするとき,
// 重み最小のパーツの重みを最大化する
lint memo[6][6][7][7][36];
lint dfs(int t, int l, int b, int r, int k, lint ub) {
    lint& res = memo[t][l][b][r][k];
    if (res != -1) return res;

    if (k == 0) {
        res = cum[b][r] - cum[b][l] - cum[t][r] + cum[t][l];
        if (res > ub) res = -INF;
        return res;
    }

    res = -INF;
    rep(i, t + 1, b) {
        rep(k2, k) {
            chmax(res, min(dfs(t, l, i, r, k2, ub), dfs(i, l, b, r, k - k2 - 1, ub)));
        }
    }
    rep(j, l + 1, r) {
        rep(k2, k) {
            chmax(res, min(dfs(t, l, b, j, k2, ub), dfs(t, j, b, r, k - k2 - 1, ub)));
        }
    }
    return res;
}

int main() {
    int T; cin >> h >> w >> T;
    rep(i, h) rep(j, w) {
        cin >> A[i][j];
        cum[i + 1][j + 1] = cum[i + 1][j] + cum[i][j + 1] - cum[i][j] + A[i][j];
    }

    set<lint> S;
    rep(t, h) rep(b, t + 1, h + 1) rep(l, w) rep(r, l + 1, w + 1) {
        S.emplace(cum[b][r] - cum[b][l] - cum[t][r] + cum[t][l]);
    }

    lint ans = INF;
    for (auto c : S) {
        memset(memo, -1, sizeof memo);
        chmin(ans, c - dfs(0, 0, h, w, T, c));
    }
    cout << ans << endl;

    return 0;
}
