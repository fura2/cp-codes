#include "template.hpp"

const double INF = 1e30;

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> P(n);
    for (auto &[x, y] : P)
        cin >> x >> y;

    vector dp(n, vector(50, INF));
    dp[0][0] = 0;
    rep(i, 1, n) rep(k, 50) {
        rep(j, max(i - 50, 0), i) {
            double cost = hypot(P[i].first - P[j].first, P[i].second - P[j].second);
            if (k + i - j - 1 < 50) {
                chmin(dp[i][k + i - j - 1], dp[j][k] + cost);
            }
        }
    }

    double ans = dp[n - 1][0];
    rep(k, 1, 50) chmin(ans, dp[n - 1][k] + (1LL << (k - 1)));
    cout << ans << endl;

    return 0;
}
