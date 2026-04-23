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

vector<vector<int>> connected_components(const graph& G) {
  int n = G.size();
  vector<vector<int>> res;
  vector<bool> vis(n);
  rep (u, n)
    if (!vis[u]) {
      vis[u] = true;
      res.emplace_back();
      queue<int> Q;
      Q.emplace(u);
      while (!Q.empty()) {
        int v = Q.front();
        Q.pop();
        res.back().emplace_back(v);
        for (int w: G[v])
          if (!vis[w]) {
            vis[w] = true;
            Q.emplace(w);
          }
      }
    }
  return res;
}

int main() {
  int m;
  cin >> m;
  vector<int> V;
  vector<pair<int, int>> E(m);
  rep (i, m) {
    int x, r;
    cin >> x >> r;
    V.emplace_back(x - r);
    V.emplace_back(x + r);
    E[i] = {x - r, x + r};
  }
  ranges::sort(V);
  V.erase(ranges::unique(V).begin(), V.end());

  int n = V.size();
  graph G(n);
  for (auto [u, v]: E) {
    int x = ranges::lower_bound(V, u) - V.begin();
    int y = ranges::lower_bound(V, v) - V.begin();
    add_undirected_edge(G, x, y);
  }

  int ans = 0;
  for (auto c: connected_components(G)) {
    int nc = c.size();
    int mc = 0;
    for (int u: c) mc += G[u].size();
    mc /= 2;
    ans += nc - (mc == nc - 1 ? 1 : 0);
  }
  cout << ans << endl;

  return 0;
}
