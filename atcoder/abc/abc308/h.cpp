// 解説を見て upsolve
// https://atcoder.jp/contests/abc308/editorial/6709

#include "template.hpp"

using graph = vector<vector<int>>;

template<class T> struct edge {
    int to;
    T wt;
    edge(int to, const T& wt):to(to), wt(wt) {}
};
template<class T> using weighted_graph = vector<vector<edge<T>>>;

template<class T>
void add_undirected_edge(weighted_graph<T>& G, int u, int v, const T& wt) {
    G[u].emplace_back(v, wt);
    G[v].emplace_back(u, wt);
}

const lint INF = 1LL << 61;

pair<lint, vector<int>> shortest_cycle(const weighted_graph<lint>& G, int s) {
    int n = G.size();

    priority_queue<pair<lint, int>> Q;
    Q.emplace(0, s);
    vector<lint> d(n, INF);
    d[s] = 0;
    vector<int> par(n, -1), label(n, -1);
    label[s] = s;
    while (!Q.empty()) {
        auto [md, u] = Q.top();
        Q.pop();
        if (-md > d[u]) continue;
        for (const auto& e : G[u]) {
            int v = e.to;
            if (chmin(d[v], d[u] + e.wt)) {
                par[v] = u;
                label[v] = (u == s ? v : label[u]);
                Q.emplace(-d[v], v);
            }
        }
    }

    lint len = INF;
    int u_opt = -1, v_opt = -1;
    rep(u, n) {
        for (const auto& e : G[u]) {
            int v = e.to;
            if (par[v] == u || par[u] == v || label[u] == label[v]) continue;
            if (chmin(len, d[u] + e.wt + d[v])) {
                u_opt = u;
                v_opt = v;
            }
        }
    }
    if (len == INF) return { len, {} };

    assert(u_opt != -1 && v_opt != -1);
    vector<int> C = { s };
    for (int u = u_opt; u != s; u = par[u]) {
        C.emplace_back(u);
    }
    reverse(C.begin() + 1, C.end());
    for (int v = v_opt; v != s; v = par[v]) {
        C.emplace_back(v);
    }
    return { len, C };
}

int main() {
    int n, m; cin >> n >> m;
    weighted_graph<lint> G(n);
    rep(i, m) {
        int u, v;
        lint c; cin >> u >> v >> c; u--; v--;
        add_undirected_edge(G, u, v, c);
    }

    lint ans = INF;
    rep(u, n) {
        auto [len, C] = shortest_cycle(G, u);
        if (len == INF) continue; // cycle which contains u does not exist

        assert(C.size() >= 3 && C[0] == u);
        int a = C[1], b = C.back();
        for (const auto& e : G[u]) { // 辺 e が Q のひげになるケース
            if (e.to != a && e.to != b) chmin(ans, len + e.wt);
        }

        for (int v : {a, b}) { // 辺 (u, v) が Q のひげになるケース
            auto H = G; // G から辺 (u, v) を除いてできるグラフ
            lint cost = -1;
            rep(i, ssize(H[u])) if (H[u][i].to == v) {
                cost = H[u][i].wt;
                H[u].erase(H[u].begin() + i);
                break;
            }
            rep(i, ssize(H[v])) if (H[v][i].to == u) {
                H[v].erase(H[v].begin() + i);
                break;
            }
            assert(cost != -1);
            chmin(ans, shortest_cycle(H, u).first + cost);
        }
    }
    cout << (ans < INF ? ans : -1) << endl;

    return 0;
}
