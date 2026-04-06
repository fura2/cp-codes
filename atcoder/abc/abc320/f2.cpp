#include "template.hpp"

const lint INF = 1LL << 61;

int main() {
    int n, h;
    cin >> n >> h;
    vector<int> X(n + 1), F(n + 1);
    vector<lint> P(n + 1);
    rep (i, n) cin >> X[i + 1];
    rep (i, n - 1) cin >> P[i + 1] >> F[i + 1];

    vector memo(n + 1, vector(h + 1, vector(h + 1, -1LL)));
    auto dfs = [&](auto&& dfs, int i, int h1, int h2) -> lint {
        if (i == n) {
            if (h1 >= h2) return 0;
            return INF;
        }

        int d = X[i + 1] - X[i];
        if (h1 - d < 0 or h2 + d > h) {
            return INF;
        }

        lint& res = memo[i][h1][h2];
        if (res != -1) return res;

        res = INF;
        // 地点 i+1 で補給しない
        chmin(res, dfs(dfs, i + 1, h1 - d, h2 + d));
        // 地点 i+1 で行きに補給
        chmin(res, dfs(dfs, i + 1, min(h1 - d + F[i + 1], h), h2 + d) + P[i + 1]);
        // 地点 i+1 で帰りに補給
        if (h2 + d - F[i + 1] >= 0) {
            chmin(res, dfs(dfs, i + 1, h1 - d, h2 + d - F[i + 1]) + P[i + 1]);
        }
        // 地点 i+1 で帰りに 1 リットル捨てる
        if (h2 < h) {
            chmin(res, dfs(dfs, i, h1, h2 + 1));
        }
        return res;
    };

    lint ans = dfs(dfs, 0, h, 0);
    cout << (ans < INF ? ans : -1) << endl;

    return 0;
}
