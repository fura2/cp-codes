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
    std::cout << std::fixed << std::setprecision(11);
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

int main() {
  int n;
  cin >> n;
  graph T(n);
  rep (i, n - 1) {
    int u, v;
    cin >> u >> v;
    add_undirected_edge(T, u, v);
  }

  vector<int> par(n, -1);
  vector<lint> sz(n, 1);
  vector<int> anc(n, -1); // anc[u] = (u の祖先のうち, 根 0 の子であるもの)
  auto dfs = [&](auto dfs, int u, int p) -> void {
    par[u] = p;
    if (u != 0) {
      anc[u] = (p == 0 ? u : anc[p]);
    }
    for (int v: T[u]) {
      if (v == p) continue;
      dfs(dfs, v, u);
      sz[u] += sz[v];
    }
  };
  dfs(dfs, 0, -1);

  vector<bool> vis(n);
  vis[0] = true;

  lint ans = 0;
  { // 頂点 0 を通らないパスの寄与
    ans += lint(n) * (n + 1) / 2;
    for (int u: T[0]) ans -= sz[u] * (sz[u] + 1) / 2;
  }

  int l = 0, r = 0;
  rep (u, 1, n) {
    if (!vis[u]) { // u が l-r パス上にない
      int v = u;
      do {
        vis[v] = true;
        v = par[v];
      } while (!vis[v]);
      if (v == l) {
        l = u;
      }
      else if (v == r) {
        r = u;
      }
      else { // 0, 1, ..., u を一つのパスで覆えない
        break;
      }
    }

    if (l == 0) {
      assert(r != 0);
      ans += (n - sz[anc[r]]) * sz[r];
    }
    else if (r == 0) {
      ans += sz[l] * (n - sz[anc[l]]);
    }
    else {
      ans += sz[l] * sz[r];
    }
  }

  cout << ans << endl;

  return 0;
}
