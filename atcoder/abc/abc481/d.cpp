#include "template/template.hpp"

// #define MULTI_TESTCASE
#include "graph/bfs_01.hpp"
#include "graph/digraph.hpp"
#include "graph/weighted_digraph.hpp"
#include "template/main.hpp"

void testcase() {
  auto n = input<int>(), m = input<int>(), s = input<int>() - 1,
       t = input<int>() - 1;
  auto G = input<Digraph>(n, m, 1);

  WeightedDigraph<int> H(n, m);
  rep (u, n) {
    int mn = n;
    for (const auto& e: G[u]) chmin(mn, e.to);
    for (const auto& e: G[u]) {
      H.add_edge(u, e.to, e.to == mn ? 0 : 1);
    }
  }

  int ans = bfs_01(H, s)[t];
  output(ans < INF ? ans : -1);
}
