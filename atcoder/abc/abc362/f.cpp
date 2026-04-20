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

vector<int> centroid(const graph& T) {
  int n = T.size();
  vector<int> C;
  auto dfs = [&](auto dfs, int u, int p) -> int {
    int sz = 1, mx = 0;
    for (int v: T[u]) {
      if (v == p) continue;
      int z = dfs(dfs, v, u);
      chmax(mx, z);
      sz += z;
    }
    chmax(mx, n - sz);
    if (mx <= n / 2) C.emplace_back(u);
    return sz;
  };
  dfs(dfs, 0, -1);
  return C;
}

int main() {
  int n;
  cin >> n;
  graph T(n);
  rep (i, n - 1) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    add_undirected_edge(T, u, v);
  }

  int c = centroid(T)[0];

  vector<int> seq;
  auto dfs = [&](auto dfs, int u, int p) -> void {
    if (!(n % 2 == 1 && u == c)) seq.emplace_back(u);
    for (int v: T[u]) {
      if (v == p) continue;
      dfs(dfs, v, u);
    }
  };
  dfs(dfs, c, -1);

  rep (i, n / 2) {
    cout << seq[i] + 1 << " " << seq[i + n / 2] + 1 << "\n";
  }

  return 0;
}
