#include "template.hpp"

const int INF = 1 << 29;

int main() {
    int m;
    cin >> m;
    string s[3];
    rep (i, 3) cin >> s[i];

    int ans = INF;
    rep (i, 3 * m) {
        rep (j, 3 * m) {
            rep (k, 3 * m) {
                if (i == j or i == k or j == k) continue;
                if (s[0][i % m] == s[1][j % m] and s[0][i % m] == s[2][k % m]) {
                    chmin(ans, max({i, j, k}));
                }
            }
        }
    }
    cout << (ans < INF ? ans : -1) << endl;

    return 0;
}
