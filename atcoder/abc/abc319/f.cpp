#include "template.hpp"

using graph = vector<vector<int>>;

void add_undirected_edge(graph& G, int u, int v) {
    G[u].emplace_back(v);
    G[v].emplace_back(u);
}

int main() {
    int n;
    cin >> n;
    graph G(n);
    vector<int> type(n);
    vector<lint> power(n), gain(n);
    rep (u, 1, n) {
        int p;
        cin >> p >> type[u] >> power[u] >> gain[u];
        p--;
        add_undirected_edge(G, p, u);
    }

    vector<int> potions;
    rep (u, 1, n) {
        if (type[u] == 2) potions.emplace_back(u);
    }
    int m = size(potions);

    vector<lint> dp(1 << m, -1); // set of used potions (S) -> max strength
    vector vis(1 << m, vector(n, false)); // S -> visited vertices when dp[S] is achieved
    {
        priority_queue<pair<lint, int>> Q;
        Q.emplace(0, 0);
        lint p = 1;
        while (not Q.empty()) {
            auto [_, u] = Q.top();
            Q.pop();
            if (vis[0][u] or p < power[u]) continue;
            vis[0][u] = true;

            p = min(p + gain[u], lint(1e9));

            for (int v: G[u]) {
                if (type[v] == 1) {
                    Q.emplace(-power[v], v);
                }
            }
        }
        dp[0] = p;
    }
    rep (S, 1 << m) {
        if (dp[S] == -1) continue;

        // use a potion
        rep (i, m) {
            if (bit(S, i) == 1) continue;
            int u0 = potions[i];
            bool ok = false;
            for (int v: G[u0]) {
                if (vis[S][v]) {
                    ok = true;
                    break;
                }
            }
            if (not ok) continue;

            lint p = min(dp[S] * gain[u0], lint(1e9));

            // beat enemies after use potion i
            vector vis2(n, false);
            priority_queue<pair<lint, int>> Q;
            rep (u, n) {
                if (vis[S][u] or u == u0) Q.emplace(0, u);
            }
            while (not Q.empty()) {
                auto [_, u] = Q.top();
                Q.pop();
                if (vis2[u] or p < power[u]) continue;
                vis2[u] = true;

                if (not(vis[S][u] or u == u0)) {
                    p = min(p + gain[u], lint(1e9));
                }

                for (int v: G[u]) {
                    if (type[v] == 1) {
                        Q.emplace(-power[v], v);
                    }
                }
            }

            int S2 = S | (1 << i);
            if (chmax(dp[S2], p)) {
                vis[S2] = vis2;
            }
        }
    }

    yesno(count(all(vis[(1 << m) - 1]), true) == n);

    return 0;
}
