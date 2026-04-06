#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); i++)

using namespace std;

const int64_t INF = 1LL << 61;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);

    int x, y, z; cin >> x >> y >> z;
    string s; cin >> s;
    int n = s.size();

    int64_t dp[300001][2];
    rep(i, n + 1) rep(b, 2) dp[i][b] = INF;
    dp[0][0] = 0;
    rep(i, n) {
        if (s[i] == 'a') {
            dp[i + 1][0] = min(dp[i][0] + x, dp[i][1] + z + x);
            dp[i + 1][1] = min(dp[i][0] + z + y, dp[i][1] + y);
        }
        else {
            dp[i + 1][0] = min(dp[i][1] + z + y, dp[i][0] + y);
            dp[i + 1][1] = min(dp[i][1] + x, dp[i][0] + z + x);
        }
    }
    cout << min(dp[n][0], dp[n][1]) << endl;

    return 0;
}
