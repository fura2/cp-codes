// (1) まず、赤頂点どうしを結ぶ赤辺、青頂点どうしを結ぶ青辺は (閉路ができない範囲で) 全部使っていい。
// (2) 次に、
// ・赤頂点 r と青頂点 b を結ぶ赤辺 : 有向辺 b→r
// ・赤頂点 r と青頂点 b を結ぶ青辺 : 有向辺 r→b
//   と辺を張った有向グラフ G を考えると、辺に沿って移動することで移動先の頂点が「色の条件を満たす」ようになる。
//   (1) で「色の条件を満たした」頂点たちからスタートして G 上をBFSする。
//   このとき辿った辺を答えに加える。訪問できない頂点があれば答えはNo。
// (3) 最後に、答えが連結になるように、未使用の辺を適当に答えに加える。

#include "template.hpp"

class union_find {
    int n;
    vector<int> p;

  public:
    union_find(int n = 0) { build(n); }
    void build(int n) {
        this->n = n;
        p.assign(n, -1);
    }
    int find(int u) { return p[u] < 0 ? u : p[u] = find(p[u]); }
    void unite(int u, int v) {
        u = find(u);
        v = find(v);
        if (u != v) {
            if (p[v] < p[u])
                swap(u, v);
            p[u] += p[v];
            p[v] = u;
            n--;
        }
    }
    bool is_same(int u, int v) { return find(u) == find(v); }
    int size() const { return n; }
    int size(int u) { return -p[find(u)]; }
};

template <class T>
struct edge {
    int to;
    T wt;
    edge(int to, const T &wt) : to(to), wt(wt) {}
};
template <class T>
using weighted_graph = vector<vector<edge<T>>>;

template <class T>
void add_directed_edge(weighted_graph<T> &G, int u, int v, const T &wt) {
    G[u].emplace_back(v, wt);
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<tuple<int, int, char>> E(m);
    rep(i, m) {
        int u, v;
        char c;
        cin >> u >> v >> c;
        u--;
        v--;
        E[i] = {u, v, c};
    }
    string s;
    cin >> s;

    vector<int> ans;
    weighted_graph<int> G(n);
    union_find U(n);
    rep(i, m) {
        auto [u, v, c] = E[i];
        if (s[u] == c && s[v] == c) {
            if (!U.is_same(u, v)) {
                U.unite(u, v);
                ans.emplace_back(i);
            }
        } else if (s[v] == c) {
            add_directed_edge(G, u, v, i);
        } else if (s[u] == c) {
            add_directed_edge(G, v, u, i);
        }
    }

    vector<bool> vis(n);
    queue<int> Q;
    rep(u, n) if (U.size(u) >= 2) {
        vis[u] = true;
        Q.emplace(u);
    }
    while (!Q.empty()) {
        int u = Q.front();
        Q.pop();
        for (auto e : G[u]) {
            auto [v, id] = e;
            if (!vis[v]) {
                assert(!U.is_same(u, v));
                U.unite(u, v);
                vis[v] = true;
                Q.emplace(v);
                ans.emplace_back(id);
            }
        }
    }

    if (count(all(vis), false) > 0) {
        no();
        return 0;
    }

    rep(i, m) {
        auto [u, v, c] = E[i];
        if (!U.is_same(u, v)) {
            U.unite(u, v);
            ans.emplace_back(i);
        }
    }

    yes();
    rep(i, ssize(ans)) cout << ans[i] + 1 << " ";

    return 0;
}
