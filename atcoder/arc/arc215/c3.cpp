// solution based on https://atcoder.jp/contests/arc215/editorial/16432

#ifndef TEMPLATE_HPP
#define TEMPLATE_HPP

#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>

#define impl_overload4(a, b, c, d, e, ...) e
#define impl_overload5(a, b, c, d, e, f, ...) f
#define impl_overload6(a, b, c, d, e, f, g, ...) g
#define impl_overload7(a, b, c, d, e, f, g, h, ...) h

// clang-format off
#define impl_rep4(i, a, b, c) for (int i = (a); i < (b); i += (c))
#define impl_rep3(i, a, b) impl_rep4(i, a, b, 1)
#define impl_rep2(i, n) impl_rep3(i, 0, n)
#define impl_rep1(n) for (int _ = 0; _ < (n); ++_)
#define rep(...) impl_overload4(__VA_ARGS__, impl_rep4, impl_rep3, impl_rep2, impl_rep1)(__VA_ARGS__)

#define impl_rrep4(i, a, b, c) for (int i = (b) - 1; i >= (a); i -= (c))
#define impl_rrep3(i, a, b) impl_rrep4(i, a, b, 1)
#define impl_rrep2(i, n) impl_rrep3(i, 0, n)
#define rrep(...) impl_overload4(__VA_ARGS__, impl_rrep4, impl_rrep3, impl_rrep2)(__VA_ARGS__)
// clang-format on

#define all(v) std::begin(v), std::end(v)
#define rall(v) std::rbegin(v), std::rend(v)

template<typename T>
constexpr int bit(T x, unsigned int k) {
  return (x >> k) & 1;
}

template<typename T>
constexpr bool chmax(T& a, const T& b) {
  return a < b ? a = b, true : false;
}
template<typename T>
constexpr bool chmin(T& a, const T& b) {
  return a > b ? a = b, true : false;
}

void yesno(bool b) {
  std::cout << (b ? "Yes" : "No") << "\n";
}
void yes() {
  yesno(true);
}
void no() {
  yesno(false);
}

struct Setup {
  Setup() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout << std::fixed << std::setprecision(11);
  }
} setup;

#ifdef LOCAL
#include "template_local.hpp"
#else
#define show(...) ((void)0)
#endif

using uint = unsigned int;
using lint = long long;
using ulint = unsigned long long;

using namespace std;

#endif // TEMPLATE_HPP

using graph = vector<vector<int>>;

void add_undirected_edge(graph& G, int u, int v) {
  G[u].emplace_back(v);
  G[v].emplace_back(u);
}

void add_directed_edge(graph& G, int u, int v) {
  G[u].emplace_back(v);
}

template<class T>
class strongly_connected_components {
  strongly_connected_components(const T&) = delete;
};

template<>
class strongly_connected_components<graph> {
  vector<int> id;
  vector<vector<int>> Comp;
  graph D;

 public:
  strongly_connected_components(const graph& G = {}) {
    build(G);
  }

  void build(const graph& G) {
    int n = G.size();
    graph G_rev(n);
    rep (u, n)
      for (int v: G[u]) add_directed_edge(G_rev, v, u);

    int k;
    vector<int> top(n);

    auto dfs1 = [&](auto&& dfs1, int u) -> void {
      id[u] = 0;
      for (int v: G[u])
        if (id[v] == -1) dfs1(dfs1, v);
      top[k++] = u;
    };
    auto dfs2 = [&](auto&& dfs2, int u) -> void {
      id[u] = k;
      for (int v: G_rev[u])
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
      for (int v: G[u])
        if (id[u] != id[v]) add_directed_edge(D, id[u], id[v]);
    }
  }

  int operator[](int u) const {
    return id[u];
  }

  const vector<int>& component(int i) const {
    return Comp[i];
  }
  const graph& DAG() const {
    return D;
  }
};

struct triple {
  int x, y, z;
};

void solve() {
  int n;
  cin >> n;
  vector<triple> a(n);
  rep (i, n) cin >> a[i].x >> a[i].y >> a[i].z;

  vector<int> px(n), py(n), pz(n);
  iota(all(px), 0);
  sort(all(px), [&](int i, int j) { return a[i].x > a[j].x; });
  iota(all(py), 0);
  sort(all(py), [&](int i, int j) { return a[i].y > a[j].y; });
  iota(all(pz), 0);
  sort(all(pz), [&](int i, int j) { return a[i].z > a[j].z; });

  graph G(n);
  rep (i, n - 1) {
    add_directed_edge(G, px[i], px[i + 1]);
    add_directed_edge(G, py[i], py[i + 1]);
    add_directed_edge(G, pz[i], pz[i + 1]);
    if (a[px[i]].x == a[px[i + 1]].x) add_directed_edge(G, px[i + 1], px[i]);
    if (a[py[i]].y == a[py[i + 1]].y) add_directed_edge(G, py[i + 1], py[i]);
    if (a[pz[i]].z == a[pz[i + 1]].z) add_directed_edge(G, pz[i + 1], pz[i]);
  }
  cout << strongly_connected_components(G).component(0).size() << endl;
}

int main() {
  int t;
  cin >> t;
  rep (_, t) solve();
  return 0;
}
