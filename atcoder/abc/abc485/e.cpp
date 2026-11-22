#include "template/template.hpp"

// #define MULTI_TESTCASE
#include "graph/weighted_digraph.hpp"
#include "template/main.hpp"

void testcase() {
  auto n = input<int>(), m = input<int>();
  auto G = input<WeightedDigraph<int>>(n, m, 1);

  vector<map<int, int>> d(n);
  d[0][-1] = 0;
  queue<pair<int, int>> Q;
  Q.emplace(0, -1);
  while (!Q.empty()) {
    auto [u, c] = Q.front();
    Q.pop();
    for (const auto& e: G[u]) {
      if (e.cost == c || d[e.to].size() >= 2 || d[e.to].contains(e.cost))
        continue;
      d[e.to][e.cost] = d[u][c] + 1;
      Q.emplace(e.to, e.cost);
    }
  }

  int ans = INF;
  for (auto [k, v]: d[n - 1]) chmin(ans, v);
  output(ans < INF ? ans : -1);
}
