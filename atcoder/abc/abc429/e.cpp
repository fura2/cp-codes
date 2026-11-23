#include "template/template.hpp"

// #define MULTI_TESTCASE
#include "graph/graph.hpp"
#include "template/main.hpp"

void testcase() {
  auto n = input<int>(), m = input<int>();
  auto G = input<Graph>(n, m, 1);
  auto s = input<string>();

  vector d(n, vector<pair<int, int>>());
  queue<pair<int, int>> Q;
  rep (u, n) {
    if (s[u] == 'S') {
      d[u].emplace_back(0, u);
      Q.emplace(u, u);
    }
  }
  while (!Q.empty()) {
    auto [u, u0] = Q.front();
    Q.pop();
    int du = (d[u][0].second == u0 ? d[u][0].first : d[u][1].first);
    for (const auto& e: G[u]) {
      int v = e.to;
      if (d[v].empty() || (d[v].size() == 1 && d[v][0].second != u0)) {
        d[v].emplace_back(du + 1, u0);
        Q.emplace(v, u0);
      }
    }
  }
  rep (u, n) {
    if (s[u] == 'D') {
      output(d[u][0].first + d[u][1].first);
    }
  }
}
