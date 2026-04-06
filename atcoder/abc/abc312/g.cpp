#include "template.hpp"

using graph = vector<vector<int>>;

void add_undirected_edge(graph& G, int u, int v) {
    G[u].emplace_back(v);
    G[v].emplace_back(u);
}

int main() {
    int n; cin >> n;
    graph T(n);
    rep(i, n - 1) {
        int u, v; cin >> u >> v; u--; v--;
        add_undirected_edge(T, u, v);
    }

    vector<int> sz(n);
    auto dfs1 = [&](auto&& dfs, int u, int p) -> void {
        sz[u] = 1;
        for (int v : T[u]) if (v != p) {
            dfs(dfs, v, u);
            sz[u] += sz[v];
        }
    };
    dfs1(dfs1, 0, -1);

    lint ans = 0;
    auto dfs2 = [&](auto&& dfs, int u, int p) -> void {
        vector<lint> C;
        lint n_up = n - 1;
        for (int v : T[u]) if (v != p) {
            dfs(dfs, v, u);
            C.emplace_back(sz[v]);
            n_up -= sz[v];
        }
        C.emplace_back(n_up);

        // Σ_{i<j<k} c_i*c_j*c_k を計算したい
        //   S_i = c_1^i + c_2^i + ... + c_k^i
        // とおくと,
        //   S_1^3 = S_3 + 3 Σ_{i!=j} c_i^2*c_j + 6 Σ_{i<j<k} c_i*c_j*c_k
        //   S_1 * S_2 = S_3 + Σ_{i!=j} c_i^2*c_j
        // より
        //   Σ_{i<j<k} c_i*c_j*c_k = (1/6) * (S_1^3 + 2*S_3 - 3*S_1*S_2)
        lint s1 = 0, s2 = 0, s3 = 0;
        for (auto c : C) {
            s1 += c;
            s2 += c * c;
            s3 += c * c * c;
        }
        ans += (s1 * s1 * s1 + 2 * s3 - 3 * s1 * s2) / 6;
    };
    dfs2(dfs2, 0, -1);

    cout << ans << endl;

    return 0;
}
