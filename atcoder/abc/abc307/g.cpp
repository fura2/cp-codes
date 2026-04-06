#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); i++)
#define all(v) (v).begin(), (v).end()

using namespace std;

const long INF = 1L << 61;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n; cin >> n;
    vector<long> a(n);
    rep(i, n) cin >> a[i];

    long sum = accumulate(all(a), 0L);
    long mean = sum / n;
    if (sum < n * mean) {
        mean--;
    }
    int r = sum - n * mean;
    rep(i, n) a[i] -= mean;

    vector<long> cum(n + 1);
    rep(i, n) cum[i + 1] = cum[i] + a[i];
    assert(cum[n] == r);

    // cum[1..n) の各要素に操作 cum[i] += 1 or cum[i] -= 1 を施して
    //   cum[n] == r and 0 <= cum[i+1] - cum[i] <= 1
    // を満たすようにするために必要な操作回数の最小値を求める
    vector dp(n + 1, vector<long>(r + 1, INF));
    dp[0][0] = 0;
    rep(i, n) rep(j, r + 1) {
        if (dp[i][j] == INF) continue;
        dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + abs(j - cum[i + 1]));
        if (j + 1 <= r) {
            dp[i + 1][j + 1] = min(dp[i + 1][j + 1], dp[i][j] + abs(j + 1 - cum[i + 1]));
        }
    }
    cout << dp[n][r] << endl;

    return 0;
}
