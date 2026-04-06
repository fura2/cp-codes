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

int main() {
  int n, m;
  cin >> n >> m;
  vector<pair<int, int>> E;
  rep (i, m) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    if (u != v) E.emplace_back(u, v);
  }
  sort(all(E));
  E.erase(unique(all(E)), E.end());

  graph G(n), rG(n);
  for (auto [u, v]: E) {
    add_directed_edge(G, u, v);
    add_directed_edge(rG, v, u);
  }

  int viscnt = 0;
  vector<bool> vis(n);
  auto dfs = [&](auto&& dfs, int u, int k) -> void {
    vis[u] = true;
    viscnt++;
    for (int v: G[u])
      if (!vis[v] && v <= k) dfs(dfs, v, k);
  };

  int largecnt = 0;
  vector<int> large(n);
  rep (u, n) {
    bool ok = (u == 0);
    for (int v: rG[u]) {
      if (vis[v]) ok = true;
    }
    if (ok) dfs(dfs, u, u);

    for (int v: G[u])
      if (u < v) {
        if (large[v] == 0) largecnt++;
        large[v]++;
      }
    for (int v: rG[u]) {
      if (v < u) {
        large[u]--;
        if (large[u] == 0) largecnt--;
      }
    }

    if (viscnt < u + 1) {
      cout << -1 << endl;
    }
    else {
      cout << largecnt << endl;
    }
  }

  return 0;
}
