#include "template.hpp"

using graph = vector<vector<int>>;

void add_directed_edge(graph &G, int u, int v) {
    G[u].emplace_back(v);
}

int main() {
    int n;
    cin >> n;
    graph D(n);
    rep(u, n) {
        int k;
        cin >> k;
        rep(k) {
            int v;
            cin >> v;
            v--;
            add_directed_edge(D, u, v);
        }
    }

    vector<int> ans;
    vector<bool> vis(n);
    auto dfs = [&](auto &&dfs, int u) -> void {
        vis[u] = true;
        for (int v : D[u]) {
            if (!vis[v]) {
                dfs(dfs, v);
            }
        }
        ans.emplace_back(u);
    };
    dfs(dfs, 0);
    rep(i, ssize(ans) - 1) {
        cout << ans[i] + 1 << " \n"[i < ssize(ans) - 2 ? 0 : 1];
    }

    return 0;
}
