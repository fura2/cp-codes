#include "template.hpp"

int main() {
    int n, m;
    cin >> n >> m;
    vector D(n, vector(n, -1));
    rep (i, m) {
        int u, v;
        lint c;
        cin >> u >> v >> c;
        u--;
        v--;
        D[u][v] = D[v][u] = c;
    }

    lint ans = 0;
    vector<int> P(n);
    iota(all(P), 0);
    do {
        lint cost = 0;
        rep (i, n - 1) {
            if (D[P[i]][P[i + 1]] < 0) {
                break;
            }
            cost += D[P[i]][P[i + 1]];
        }
        chmax(ans, cost);
    } while (next_permutation(all(P)));
    cout << ans << endl;

    return 0;
}
