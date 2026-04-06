#include "template.hpp"

const lint INF = 1LL << 61;

int main() {
    int n;
    cin >> n;
    vector D(n, vector<lint>(n));
    rep (u, n) {
        rep (v, u + 1, n) {
            cin >> D[u][v];
            D[v][u] = D[u][v];
        }
    }

    vector<lint> dp(1 << n, -INF);
    dp[0] = 0;
    rep (u, n) {
        rep (v, u + 1, n) {
            rep (S, 1 << n) {
                if (bit(S, u) == 0 and bit(S, v) == 0) {
                    chmax(dp[S | (1 << u) | (1 << v)], dp[S] + D[u][v]);
                }
            }
        }
    }
    cout << *max_element(all(dp)) << endl;

    return 0;
}
