#include "template.hpp"

int main() {
    int n, m; cin >> n >> m;
    bool A[50][50] = {};
    rep(i, m) {
        int u, v; cin >> u >> v; u--; v--;
        A[u][v] = true;
    }

    rep(k, n) rep(i, n) rep(j, n) {
        A[i][j] |= A[i][k] && A[k][j];
    }

    int ans = -1;
    rep(u, n) {
        bool ok = true;
        rep(v, n) if (A[v][u]) ok = false;
        if (ok) {
            if (ans == -1) ans = u;
            else {
                cout << -1 << endl;
                return 0;
            }
        }
    }
    cout << ans + 1 << endl;

    return 0;
}
