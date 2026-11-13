#include "template/template.hpp"

// #define MULTI_TESTCASE
#include "graph/weighted_digraph.hpp"
#include "template/main.hpp"

void testcase() {
  auto n = input<int>(), m = input<int>();
  auto G = input<WeightedDigraph<int>>(n, m, 1);

  int k = 1 << 10;
  vector vis(n, vector(k, false));
  vis[0][0] = true;
  queue<pair<int, int>> Q;
  Q.emplace(0, 0);
  while (!Q.empty()) {
    auto [u, x] = Q.front();
    Q.pop();
    for (auto e: G[u]) {
      int y = x ^ e.cost;
      if (!vis[e.to][y]) {
        vis[e.to][y] = true;
        Q.emplace(e.to, y);
      }
    }
  }

  int ans = INF;
  rrep (x, k)
    if (vis[n - 1][x]) ans = x;
  if (ans == INF) ans = -1;
  output(ans);
}
