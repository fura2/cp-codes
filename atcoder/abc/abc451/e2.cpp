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

using graph = vector<vector<int>>;

void add_undirected_edge(graph& G, int u, int v) {
  G[u].emplace_back(v);
  G[v].emplace_back(u);
}

void add_directed_edge(graph& G, int u, int v) {
  G[u].emplace_back(v);
}

using Edge = tuple<int, int, int>;
vector<Edge> kruskal(int n, vector<Edge> E) {
  sort(E.begin(), E.end(), [](const auto& e, const auto& f) { return get<2>(e) < get<2>(f); });

  vector<Edge> res;
  union_find U(n);
  for (const auto& e: E) {
    const auto& [u, v, wt] = e;
    if (!U.is_same(u, v)) {
      U.unite(u, v);
      res.emplace_back(e);
    }
  }
  return res;
}

int main() {
  int n;
  cin >> n;
  vector d(n, vector<int>(n));
  vector<Edge> E;
  rep (u, n) {
    rep (v, u + 1, n) {
      cin >> d[u][v];
      d[v][u] = d[u][v];
      E.emplace_back(u, v, d[u][v]);
    }
  }

  auto F = kruskal(n, E);
  graph T(n);
  for (auto [u, v, c]: F) {
    add_undirected_edge(T, u, v);
  }

  bool ok = true;
  auto dfs = [&](auto&& dfs, int u, int p, int sum, int r) -> void {
    if (d[r][u] != sum) ok = false;
    if (!ok) return;
    for (int v: T[u])
      if (v != p) {
        dfs(dfs, v, u, sum + d[u][v], r);
      }
  };
  rep (r, n) {
    dfs(dfs, r, -1, 0, r);
  }
  yesno(ok);

  return 0;
}
