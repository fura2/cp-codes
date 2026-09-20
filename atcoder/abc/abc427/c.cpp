#include "template/template.hpp"

// #define MULTI_TESTCASE
#include "graph/graph.hpp"
#include "template/main.hpp"

void testcase() {
  auto n = input<int>(), m = input<int>();
  auto G = input<Graph>(n, m, 1);

  int ans = m;
  rep (S, 1 << n) {
    int cnt = 0;
    rep (i, m) {
      auto e = G.edge(i);
      if (bit(S, e.from) == bit(S, e.to)) cnt++;
    }
    chmin(ans, cnt);
  }
  output(ans);
}
