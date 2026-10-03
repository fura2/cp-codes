#include "template/template.hpp"

// #define MULTI_TESTCASE
#include "template/main.hpp"

template <class T>
struct edge {
  int to;
  T wt;
  edge(int to, const T& wt): to(to), wt(wt) {
  }
};
template <class T>
using weighted_graph = vector<vector<edge<T>>>;

template <class T>
void add_undirected_edge(weighted_graph<T>& G, int u, int v, const T& wt) {
  G[u].emplace_back(v, wt);
  G[v].emplace_back(u, wt);
}

template <class T>
void add_directed_edge(weighted_graph<T>& G, int u, int v, const T& wt) {
  G[u].emplace_back(v, wt);
}

template <class T>
class strongly_connected_components {
  strongly_connected_components(const T&) = delete;
};

template <class W>
class strongly_connected_components<weighted_graph<W>> {
  vector<int> id;
  vector<vector<int>> Comp;
  weighted_graph<W> D;

 public:
  strongly_connected_components(const weighted_graph<W>& G = {}) {
    build(G);
  }

  void build(const weighted_graph<W>& G) {
    int n = G.size();
    weighted_graph<W> G_rev(n);
    rep (u, n)
      for (const auto& [v, wt]: G[u]) add_directed_edge(G_rev, v, u, wt);

    int k;
    vector<int> top(n);

    auto dfs1 = [&](auto&& dfs1, int u) -> void {
      id[u] = 0;
      for (const auto& [v, wt]: G[u])
        if (id[v] == -1) dfs1(dfs1, v);
      top[k++] = u;
    };
    auto dfs2 = [&](auto&& dfs2, int u) -> void {
      id[u] = k;
      for (const auto& [v, wt]: G_rev[u])
        if (id[v] == -1) dfs2(dfs2, v);
    };

    k = 0;
    id.assign(n, -1);
    rep (u, n)
      if (id[u] == -1) dfs1(dfs1, u);

    reverse(top.begin(), top.end());

    k = 0;
    id.assign(n, -1);
    for (int u: top)
      if (id[u] == -1) dfs2(dfs2, u), k++;

    Comp.resize(k);
    D.resize(k);
    rep (u, n) {
      Comp[id[u]].emplace_back(u);
      for (const auto& [v, wt]: G[u])
        if (id[u] != id[v]) add_directed_edge(D, id[u], id[v], wt);
    }
  }

  int operator[](int u) const {
    return id[u];
  }

  const vector<int>& component(int i) const {
    return Comp[i];
  }
  const weighted_graph<W>& DAG() const {
    return D;
  }
};

void testcase() {
  auto n = input<int>(), q = input<int>();
  weighted_graph<int> G(n);
  rep (i, q) {
    auto t = input<int>(), u = input<int>() - 1, v = input<int>() - 1;
    add_directed_edge(G, u, v, t);
  }

  strongly_connected_components scc(G);
  rep (u, n) {
    for (const auto& e: G[u]) {
      if (scc[u] == scc[e.to] && e.wt == 1) {
        no();
        return;
      }
    }
  }
  auto D = scc.DAG();
  int nd = D.size();
  vector<int> res(nd, 1);
  res[0] = 1;
  rep (i, nd) {
    for (const auto& e: D[i]) {
      chmax(res[e.to], res[i] + e.wt);
    }
  }
  vector<int> ans(n);
  rep (u, n) ans[u] = res[scc[u]];
  yes();
  output(ans);
}
