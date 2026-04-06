#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); i++)

using namespace std;

using graph = vector<vector<int>>;

void add_undirected_edge(graph& G, int u, int v) {
    G[u].emplace_back(v);
    G[v].emplace_back(u);
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);

    int n, m, k; cin >> n >> m >> k;
    graph G(n);
    rep(i, m) {
        int u, v; cin >> u >> v; u--; v--;
        add_undirected_edge(G, u, v);
    }

    vector<int> d(n, -1); // 動ける回数
    priority_queue<pair<int, int>> Q;
    rep(i, k) {
        int p, h; cin >> p >> h; p--;
        d[p] = h;
        Q.emplace(h, p);
    }
    while (!Q.empty()) {
        int u = Q.top().second; Q.pop();
        if (d[u] == 0) continue;

        for (int v : G[u]) {
            if (d[v] < d[u] - 1) {
                d[v] = d[u] - 1;
                Q.emplace(d[v], v);
            }
        }
    }

    vector<int> ans;
    rep(u, n) if (d[u] != -1) ans.emplace_back(u);
    cout << ans.size() << "\n";
    for (int u : ans) cout << u + 1 << " ";

    return 0;
}
