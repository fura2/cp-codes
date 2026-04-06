// solution based on 公式解説放送

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

void solve() {
  int n;
  cin >> n;
  graph T(n);
  rep (i, n - 1) {
    int u, v;
    cin >> u >> v;
    u--;
    v--;
    add_undirected_edge(T, u, v);
  }

  vector<int> f(n);
  auto dfs1 = [&](auto&& dfs, int u, int p) -> int {
    int mx = 0;
    for (int v: T[u]) {
      if (v == p) continue;
      chmax(mx, dfs(dfs, v, u));
    }
    if (T[u].size() >= 4) return f[u] = mx + 1; // u から下に伸びる
    if (T[u].size() == 3) return f[u] = 1; // u 単独
    return f[u] = 0;
  };
  dfs1(dfs1, 0, -1);

  int ans = 1;
  auto dfs2 = [&](auto&& dfs, int u, int p) -> void {
    int mx = 0;
    for (int v: T[u]) {
      if (v == p) continue;
      dfs(dfs, v, u);
      if (T[u].size() >= 4) chmax(ans, mx + f[v] + 1); // u で折り返す
      chmax(mx, f[v]);
      if (T[u].size() >= 3) chmax(ans, f[v] + 1); // u で終わる
    }
  };
  dfs2(dfs2, 0, -1);
  cout << ans << endl;
}

int main() {
  int t;
  cin >> t;
  rep (_, t) solve();
  return 0;
}
