#include "template.hpp"

int main() {
    int s, t, m; cin >> s >> t >> m;
    vector G(s, vector<int>());
    rep(i, m) {
        int u, v; cin >> u >> v; u--; v--;
        G[u].emplace_back(v);
    }

    rep(u, s) sort(all(G[u]));

    int id[3000][3000];
    memset(id, -1, sizeof id);
    rep(u, s) {
        rep(i, ssize(G[u])) {
            rep(j, i + 1, ssize(G[u])) {
                int v = G[u][i], w = G[u][j];
                if (id[v - s][w - s] != -1) {
                    cout << id[v - s][w - s] + 1 << " " << u + 1 << " " << v + 1 << " " << w + 1 << endl;
                    return 0;
                }
                id[v - s][w - s] = u;
            }
        }
    }
    cout << -1 << endl;

    return 0;
}
