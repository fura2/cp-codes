// 重みが小さい辺から順に見ていく.
// 今見ている辺の端点をできるだけ異なる色で塗るようにすればよい.
// これは, 辺がないグラフから始めて, 閉路ができない限り辺を加えてできる二部グラフ (木) の頂点彩色に他ならない.
// 答え自体は, 長さが高々2のパスだけ考えればいいことから求められる.

#include "template.hpp"

using graph = vector<vector<int>>;

void add_undirected_edge(graph& G, int u, int v) {
    G[u].emplace_back(v);
    G[v].emplace_back(u);
}

template<class T>
struct edge {
    int to;
    T wt;
    edge(int to, const T& wt): to(to), wt(wt) {}
};
template<class T>
using weighted_graph = vector<vector<edge<T>>>;

template<class T>
void add_undirected_edge(weighted_graph<T>& G, int u, int v, const T& wt) {
    G[u].emplace_back(v, wt);
    G[v].emplace_back(u, wt);
}

class union_find {
    int n;
    vector<int> p;

  public:
    union_find(int n = 0) {
        build(n);
    }
    void build(int n) {
        this->n = n;
        p.assign(n, -1);
    }
    int find(int u) {
        return p[u] < 0 ? u : p[u] = find(p[u]);
    }
    void unite(int u, int v) {
        u = find(u);
        v = find(v);
        if (u != v) {
            if (p[v] < p[u]) swap(u, v);
            p[u] += p[v];
            p[v] = u;
            n--;
        }
    }
    bool is_same(int u, int v) {
        return find(u) == find(v);
    }
    int size() const {
        return n;
    }
    int size(int u) {
        return -p[find(u)];
    }
};

pair<bool, vector<int>> two_coloring(const graph& G) {
    int n = G.size();
    vector<int> color(n, -1);
    rep (u, n)
        if (color[u] == -1) {
            color[u] = 0;
            queue<int> Q;
            Q.emplace(u);
            while (!Q.empty()) {
                int v = Q.front();
                Q.pop();
                for (int w: G[v]) {
                    if (color[w] == -1) {
                        color[w] = 1 - color[v];
                        Q.emplace(w);
                    }
                    else if (color[w] == color[v])
                        return {false, vector<int>()};
                }
            }
        }
    return {true, color};
}

const lint INF = 1LL << 61;

int main() {
    int n, m;
    cin >> n >> m;
    weighted_graph<lint> G(n);
    vector<tuple<int, int, lint>> E(m);
    rep (i, m) {
        int u, v;
        lint c;
        cin >> u >> v >> c;
        u--;
        v--;
        add_undirected_edge(G, u, v, c);
        E[i] = {u, v, c};
    }

    sort(all(E), [&](const auto& e1, const auto& e2) { return get<2>(e1) < get<2>(e2); });

    graph B(n);
    union_find U(n);
    for (auto [u, v, c]: E) {
        if (not U.is_same(u, v)) {
            U.unite(u, v);
            add_undirected_edge(B, u, v);
        }
    }

    vector<int> color = two_coloring(B).second;
    lint ans = INF;
    for (auto [u, v, c]: E) {
        if (color[u] == color[v]) {
            chmin(ans, c);
        }
    }
    rep (u, n) {
        vector<lint> C;
        for (auto e: G[u]) {
            if (color[u] != color[e.to]) {
                C.emplace_back(e.wt);
            }
        }
        sort(all(C));
        if (size(C) >= 2) chmin(ans, C[0] + C[1]);
    }
    cout << ans << endl;

    return 0;
}
