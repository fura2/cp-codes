#include "template.hpp"

int main() {
    int n;
    string s; cin >> n >> s;

    vector<int> a(n);
    rep(i, n) a[i] = s[i] - '0';

    vector dp(n + 1, vector(2, 0LL));
    rep(i, n) {
        dp[i + 1][a[i]] += 1;
        dp[i + 1][!(a[i] & 0)] += dp[i][0];
        dp[i + 1][!(a[i] & 1)] += dp[i][1];
    }

    lint ans = 0;
    rep(i, n + 1) ans += dp[i][1];
    cout << ans << endl;

    return 0;
}
