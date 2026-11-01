#include "template/template.hpp"

// #define MULTI_TESTCASE
#include "graph/tree.hpp"
#include "template/main.hpp"

void testcase() {
  auto n = input<int>();
  auto T = input<Tree>(n, 1);
  auto col = input<vector<int>>(n);

  auto [cen, diam] = T.centers();

  vector<int> dists(n);
  auto dfs = [&](auto&& dfs, int u, int p, int d) -> void {
    dists[u] = d;
    for (const auto& e: T[u]) {
      if (e.to != p) dfs(dfs, e.to, u, d + 1);
    }
  };

  auto dfs2 = [&](auto&& dfs2, int u, int p, vector<int>& cc) -> void {
    cc.emplace_back(u);
    for (const auto& e: T[u]) {
      if (e.to != p) dfs2(dfs2, e.to, u, cc);
    }
  };

  lint ans = 0;
  if (cen.size() == 1) {
    dfs(dfs, cen[0], -1, 0);
    map<int, lint> H;
    rep (u, n)
      if (dists[u] == diam / 2) ++H[col[u]];
    for (const auto [k, v]: H) ans += v * (v - 1) / 2;

    for (const auto& e: T[cen[0]]) {
      vector<int> cc;
      dfs2(dfs2, e.to, cen[0], cc);
      map<int, lint> H;
      for (int u: cc)
        if (dists[u] == diam / 2) ++H[col[u]];
      for (const auto [k, v]: H) ans -= v * (v - 1) / 2;
    }
  }
  else {
    dfs(dfs, cen[0], -1, 0);
    map<int, lint> H1;
    rep (u, n)
      if (dists[u] == (diam + 1) / 2) ++H1[col[u]];

    dfs(dfs, cen[1], -1, 0);
    map<int, lint> H2;
    rep (u, n)
      if (dists[u] == (diam + 1) / 2) ++H2[col[u]];

    for (const auto [k, v]: H1) ans += v * H2[k];
  }
  output(ans);
}
