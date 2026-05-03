#ifndef TEMPLATE_HPP
#define TEMPLATE_HPP

#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>

// clang-format off
#define impl_overload4(a, b, c, d, e, ...) e

#define impl_rep4(i, a, b, c) for (int i = (a); i < (b); i += (c))
#define impl_rep3(i, a, b) impl_rep4(i, a, b, 1)
#define impl_rep2(i, n) impl_rep3(i, 0, n)
#define impl_rep1(n) for (int _ = 0; _ < (n); ++_)
#define rep(...) impl_overload4(__VA_ARGS__, impl_rep4, impl_rep3, impl_rep2, impl_rep1)(__VA_ARGS__)

#define impl_rrep4(i, a, b, c) for (int i = (b) - 1; i >= (a); i -= (c))
#define impl_rrep3(i, a, b) impl_rrep4(i, a, b, 1)
#define impl_rrep2(i, n) impl_rrep3(i, 0, n)
#define rrep(...) impl_overload4(__VA_ARGS__, impl_rrep4, impl_rrep3, impl_rrep2)(__VA_ARGS__)

#define all(v) std::begin(v), std::end(v)

template<typename T>
constexpr int bit(T x, unsigned int k) { return (x >> k) & 1; }

template<typename T>
constexpr bool chmax(T& a, const T& b) { return a < b ? a = b, true : false; }
template<typename T>
constexpr bool chmin(T& a, const T& b) { return a > b ? a = b, true : false; }

constexpr void yesno(bool b) { std::cout << (b ? "Yes" : "No") << "\n"; }
constexpr void yes() { yesno(true); }
constexpr void no() { yesno(false); }

struct Setup {
  Setup() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout << std::fixed << std::setprecision(10);
  }
} setup;
// clang-format on

#ifdef LOCAL
#include "template_local.hpp"
#else
#define show(...) ((void)0)
#endif

using lint = long long;

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

void solve() {
  int n, m;
  cin >> n >> m;
  vector<pair<int, int>> E;
  rep (i, m) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    E.emplace_back(u, v);
    E.emplace_back(v, u);
  }
  rep (u, n) E.emplace_back(u, u);
  int w;
  cin >> w;
  vector<string> s(n);
  rep (i, n) cin >> s[i];

  graph G(n * w + 1);
  for (auto [u, v]: E) {
    rep (t, w) {
      if (s[u][t] == 'o' && s[v][(t + 1) % w] == 'o') {
        add_directed_edge(G, u * w + t, v * w + (t + 1) % w);
      }
    }
  }
  rep (u, n) {
    if (s[u][0] == 'o') {
      add_directed_edge(G, n * w, u * w);
    }
  }

  vector<bool> vis(n * w + 1);
  vector<bool> path(n * w + 1);

  auto dfs = [&](auto dfs, int u) -> bool {
    vis[u] = true;
    for (int v: G[u]) {
      if (path[v]) return true;
      if (vis[v]) continue;
      path[v] = true;
      bool b = dfs(dfs, v);
      path[v] = false;
      if (b) return true;
    }
    return false;
  };
  yesno(dfs(dfs, n * w));
}

int main() {
  int t;
  cin >> t;
  rep (_, t) solve();
  return 0;
}
