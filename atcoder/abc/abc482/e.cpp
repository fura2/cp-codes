#include "template/template.hpp"

// #define MULTI_TESTCASE
#include "graph/graph.hpp"
#include "template/main.hpp"

vector<int> centers(const Graph& T) {
  int n = T.num_vertices();

  int far = -1, d_far = -1;
  vector<int> prev(n);
  auto dfs = [&](auto&& dfs, int u, int p, int d) -> void {
    if (d_far < d) {
      d_far = d;
      far = u;
    }
    for (const auto& e: T[u]) {
      if (e.to == p) continue;
      prev[e.to] = u;
      dfs(dfs, e.to, u, d + 1);
    }
  };
  dfs(dfs, 0, -1, 0);
  int v0 = far;

  far = d_far = -1;
  dfs(dfs, v0, -1, 0);
  int v1 = far;

  vector<int> P;
  for (int u = v1; u != v0; u = prev[u]) {
    P.emplace_back(u);
  }
  P.emplace_back(v0);

  int m = P.size();
  if (m % 2 == 1) {
    return {P[m / 2]};
  }
  else {
    return {P[m / 2 - 1], P[m / 2]};
  }
}

void testcase() {
  auto n = input<int>();
  Graph T(n, n - 1);
  rep (i, n - 1) {
    auto u = input<int>() - 1, v = input<int>() - 1;
    T.add_edge(u, v);
  }
  auto col = input<vector<int>>(n);

  auto cen = centers(T);

  vector<int> dists(n);
  auto dfs = [&](auto&& dfs, int u, int p, int d) -> void {
    dists[u] = d;
    for (const auto& e: T[u]) {
      if (e.to != p) dfs(dfs, e.to, u, d + 1);
    }
  };

  // find leaves
  auto dfs2 = [&](auto&& dfs2, int u, int p, vector<int>& L) -> void {
    if (T.degree(u) == 1) {
      L.emplace_back(u);
    }
    for (const auto& e: T[u]) {
      if (e.to != p) dfs2(dfs2, e.to, u, L);
    }
  };

  lint ans = 0;
  if (cen.size() == 1) {
    dfs(dfs, cen[0], -1, 0);
    int mx = ranges::max(dists);
    map<int, lint> H;
    rep (u, n)
      if (dists[u] == mx) ++H[col[u]];
    for (const auto [k, v]: H) ans += v * (v - 1) / 2;

    for (const auto& e: T[cen[0]]) {
      vector<int> L;
      dfs2(dfs2, e.to, cen[0], L);
      map<int, lint> H;
      for (int u: L)
        if (dists[u] == mx) ++H[col[u]];
      for (const auto [k, v]: H) ans -= v * (v - 1) / 2;
    }
  }
  else {
    dfs(dfs, cen[0], -1, 0);
    int mx1 = ranges::max(dists);
    map<int, lint> H1;
    rep (u, n)
      if (dists[u] == mx1) ++H1[col[u]];

    dfs(dfs, cen[1], -1, 0);
    int mx2 = ranges::max(dists);
    map<int, lint> H2;
    rep (u, n)
      if (dists[u] == mx2) ++H2[col[u]];

    for (const auto [k, v]: H1) ans += v * H2[k];
  }
  output(ans);
}
