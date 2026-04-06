#include "template.hpp"

using graph = vector<vector<int>>;

void add_directed_edge(graph& G, int u, int v) {
    G[u].emplace_back(v);
}

bool is_DAG(const graph& G) {
    int n = G.size();
    vector<int> deg(n);
    rep(u, n) for (int v : G[u]) deg[v]++;

    int cnt = 0;
    queue<int> Q;
    rep(u, n) if (deg[u] == 0) Q.emplace(u);
    while (!Q.empty()) {
        int u = Q.front(); Q.pop();
        cnt++;
        for (int v : G[u]) if (--deg[v] == 0) Q.emplace(v);
    }
    return cnt == n;
}

int main() {
    int n, m; cin >> n >> m;
    graph G(n), rG(n);
    rep(i, m) {
        int u, v; cin >> u >> v; u--; v--;
        add_directed_edge(G, u, v);
        add_directed_edge(rG, v, u);
    }
    vector<int> l(n), r(n);
    rep(u, n) cin >> l[u] >> r[u], l[u]--;

    if (!is_DAG(G)) {
        no();
        return 0;
    }

    // rの制約だけがあるとき (lの制約がないとき) の, 頂点を選ぶ最適な順番 (の一つ)
    // rの値が最小のものを一つ取り, それを選ぶためにまず先祖を全部選ぶ, ということを繰り返す
    vector<int> r_order;
    {
        vector<int> p(n); // rの値の小さい順
        iota(all(p), 0);
        sort(all(p), [&](int u, int v) { return r[u] < r[v]; });

        vector<bool> vis(n);
        for (int u : p) if (!vis[u]) {
            vector<int> tmp;
            auto dfs = [&](auto&& dfs, int v) -> void {
                vis[v] = true;
                tmp.emplace_back(v);
                for (int w : rG[v]) if (!vis[w]) {
                    dfs(dfs, w);
                }
            };
            dfs(dfs, u);
            reverse(all(tmp));
            r_order.insert(r_order.end(), all(tmp));
        }
    }
    vector<int> r_order_inv(n);
    rep(i, n) r_order_inv[r_order[i]] = i;

    vector<int> deg(n);
    rep(u, n) for (int v : G[u]) deg[v]++;

    vector<int> ans;
    priority_queue<pair<int, int>> Q1; // すべての先祖が選択済みである頂点たち
    priority_queue<pair<int, int>> Q2; // すべての先祖が選択済みであって, lの条件を満たした頂点たち
    rep(u, n) if (deg[u] == 0) {
        Q1.emplace(-l[u], u);
    }
    rep(n) {
        while (!Q1.empty()) {
            int u = Q1.top().second;
            if (l[u] > ssize(ans)) break;
            Q1.pop();
            Q2.emplace(-r_order_inv[u], u); // r_orderが小さい (早く選ばないといけない) ものを優先的に選ぶ
        }
        if (!Q2.empty()) {
            int u = Q2.top().second;
            Q2.pop();
            ans.emplace_back(u);
            for (int v : G[u]) {
                deg[v]--;
                if (deg[v] == 0) Q1.emplace(-l[v], v);
            }
        }
    }

    if (ssize(ans) < n) {
        no();
        return 0;
    }
    rep(i, n) {
        int u = ans[i];
        if (!(l[u] <= i && i < r[u])) {
            no();
            return 0;
        }
    }

    yes();
    vector<int> ans_inv(n);
    rep(i, n) ans_inv[ans[i]] = i;
    rep(u, n) cout << ans_inv[u] + 1 << " ";

    return 0;
}
