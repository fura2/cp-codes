#include "template.hpp"

using graph = vector<vector<int>>;

void add_undirected_edge(graph& G, int u, int v) {
    G[u].emplace_back(v);
    G[v].emplace_back(u);
}

int main() {
    int n;
    cin >> n;
    vector<int> color(n + 1);
    rep (u, 1, n + 1) {
        cin >> color[u];
        color[u]--;
    }
    // すべての色で塗られた頂点 0 を新たに加え, これを根とする
    graph T(n + 1);
    rep (i, n - 1) {
        int u, v;
        cin >> u >> v;
        add_undirected_edge(T, u, v);
    }
    add_undirected_edge(T, 0, 1); // 頂点 0 と頂点 1 (1-indexed) の間に辺を張る

    vector<lint> sz(n + 1); // 部分木のサイズ
    vector<lint> dep(n + 1); // 深さ
    {
        auto dfs = [&](auto&& dfs, int u, int p) -> void {
            sz[u] = 1;
            if (p != -1) dep[u] = dep[p] + 1;
            for (int v: T[u]) {
                if (v != p) {
                    dfs(dfs, v, u);
                    sz[u] += sz[v];
                }
            }
        };
        dfs(dfs, 0, -1);
    }

    // 頂点 u の先祖であって u と同色の頂点のうち, u に最も近いものを a として
    //   ance[u] = (a を親とする a-u パス上の頂点)
    // つまり, a - ance[u] - ... - u という位置関係 (ance[u] == u でもよい)
    vector<int> ance(n + 1, -1);
    {
        vector<int> last(n, 0);
        vector<int> path;
        auto dfs = [&](auto&& dfs, int u, int p) -> void {
            path.emplace_back(u);

            if (p != -1) {
                int a = last[color[u]];
                ance[u] = path[dep[a] + 1];
            }

            int tmp = -1;
            if (p != -1) {
                tmp = last[color[u]];
                last[color[u]] = u;
            }

            for (int v: T[u]) {
                if (v != p) {
                    dfs(dfs, v, u);
                }
            }

            // revert
            if (p != -1) {
                last[color[u]] = tmp;
            }
            path.pop_back();
        };
        dfs(dfs, 0, -1);
    }

    vector<vector<int>> color2V(n, {0});
    rep (u, 1, n + 1) color2V[color[u]].emplace_back(u);
    rep (c, n) {
        sort(all(color2V[c]), [&](int u, int v) { return dep[u] > dep[v]; }); // 深い順
    }

    rep (c, n) {
        // 色 c で塗られた頂点を通らない単純パスを数える
        // T から色 c の頂点 (u, ...) を全部消したときの
        // - 各 ance[u] を根とする部分木のサイズ
        // - T の各葉を含む連結成分のサイズ
        // が分かればよい
        vector<int> A;
        for (int u: color2V[c]) {
            int a = ance[u];
            if (a != -1) {
                A.emplace_back(a);
            }
        }
        sort(all(A));
        A.erase(unique(all(A)), end(A));
        int k = size(A);

        map<int, int> f; // ance -> index
        rep (i, k) f[A[i]] = i;

        lint res = 0;
        vector<lint> dp(k);
        rep (i, k) {
            int a = A[i];
            dp[i] = sz[a];
        }
        for (int u: color2V[c]) {
            int a = ance[u];
            if (a != -1) {
                int i = f[a];
                dp[i] -= sz[u]; // a を根とする部分木から u を根とする部分木を切除
            }
        }
        rep (i, k) {
            // a = A[i] を根とする部分木からの寄与
            res += dp[i] * (dp[i] + 1) / 2;
        }

        for (int u: color2V[c]) {
            // u を削除することで切り離された各葉を含む連結成分からの寄与
            for (int v: T[u]) {
                if (dep[v] == dep[u] - 1) continue;
                if (not binary_search(all(A), v)) {
                    res += sz[v] * (sz[v] + 1) / 2;
                }
            }
        }

        cout << lint(n) * (n + 1) / 2 - res << "\n";
    }

    return 0;
}
