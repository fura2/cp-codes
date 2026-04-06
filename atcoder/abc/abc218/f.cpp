#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); i++)

using namespace std;
using graph = vector<vector<int>>;

void add_directed_edge(graph& G, int u, int v) {
    G[u].emplace_back(v);
}

pair<vector<int>, vector<int>> distance(const graph& G, int s) {
    constexpr int INF = INT_MAX;
    int n = G.size();
    vector<int> d(n, INF), prev(n, -1);
    d[s] = 0;
    queue<int> Q; Q.emplace(s);
    while (!Q.empty()) {
        int u = Q.front(); Q.pop();
        for (int v : G[u]) if (d[v] == INF) {
            d[v] = d[u] + 1;
            prev[v] = u;
            Q.emplace(v);
        }
    }
    return { d, prev };
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);

    int n, m; cin >> n >> m;
    vector<pair<int, int>> E(m);
    graph G(n);
    rep(i, m) {
        int u, v; cin >> u >> v; u--; v--;
        E[i] = { u, v };
        add_directed_edge(G, u, v);
    }

    auto [d, prev] = distance(G, 0);
    if (d[n - 1] == INT_MAX) {
        rep(i, m) cout << -1 << "\n";
        return 0;
    }

    vector<int> path = {};
    for (int u = n - 1; u != 0; u = prev[u]) {
        path.emplace_back(u);
    }
    path.emplace_back(0);
    reverse(path.begin(), path.end());

    rep(i, m) {
        bool ok = true;
        auto [u, v] = E[i];
        rep(i, path.size() - 1) {
            if (path[i] == u && path[i + 1] == v) {
                ok = false;
                break;
            }
        }
        if (ok) {
            cout << d[n - 1] << "\n";
        }
        else {
            graph H(n);
            rep(j, m) if (j != i) {
                int u = E[j].first, v = E[j].second;
                add_directed_edge(H, u, v);
            }
            int res = distance(H, 0).first[n - 1];
            cout << (res < INT_MAX ? res : -1) << "\n";
        }
    }

    return 0;
}
