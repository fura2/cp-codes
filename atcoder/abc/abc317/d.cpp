#include "template.hpp"

const lint INF = 1LL << 61;

int main() {
    int n;
    cin >> n;
    vector<lint> X(n), Y(n);
    vector<int> Z(n);
    rep (i, n) cin >> X[i] >> Y[i] >> Z[i];

    int zsum = accumulate(all(Z), 0);
    vector<lint> dp(zsum + 1, INF);
    dp[0] = 0;
    rep (i, n) {
        for (int w = zsum; w >= Z[i]; w--) {
            if (X[i] > Y[i]) {
                chmin(dp[w], dp[w - Z[i]]);
            }
            else {
                chmin(dp[w], dp[w - Z[i]] + (Y[i] - X[i] + 1) / 2);
            }
        }
    }

    cout << *min_element(dp.begin() + (zsum + 1) / 2, dp.end()) << endl;

    return 0;
}
