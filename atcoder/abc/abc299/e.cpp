#include "template.hpp"

using graph = vector<vector<int>>;

void add_undirected_edge(graph& G, int u, int v) {
    G[u].emplace_back(v);
    G[v].emplace_back(u);
}

vector<int> distance(const graph& G, int s) {
    constexpr int INF = INT_MAX;
    int n = G.size();
    vector<int> d(n, INF);
    d[s] = 0;
    queue<int> Q; Q.emplace(s);
    while (!Q.empty()) {
        int u = Q.front(); Q.pop();
        for (int v : G[u]) if (d[v] == INF) {
            d[v] = d[u] + 1;
            Q.emplace(v);
        }
    }
    return d;
}

int main() {
    int n, m; cin >> n >> m;
    graph G(n);
    rep(i, m) {
        int u, v; cin >> u >> v; u--; v--;
        add_undirected_edge(G, u, v);
    }
    int k; cin >> k;
    vector<int> p(k), d(k);
    rep(i, k) {
        cin >> p[i] >> d[i];
        p[i]--;
    }

    vector<int> color(n, 1);
    rep(i, k) {
        auto D = distance(G, p[i]);
        rep(u, n) if (D[u] < d[i]) color[u] = 0;
    }

    rep(i, k) {
        auto D = distance(G, p[i]);
        bool ok = false;
        rep(u, n) if (D[u] == d[i] && color[u] == 1) ok = true;
        if (!ok) {
            no();
            return 0;
        }
    }
    yes();
    rep(u, n) cout << color[u];


    return 0;
}
