#include "template/template.hpp"

// #define MULTI_TESTCASE
#include "graph/digraph.hpp"
#include "template/main.hpp"

void testcase() {
  auto n = input<int>();

  Digraph G(n);
  queue<int> Q;
  vector<bool> vis(n);
  rep (u, n) {
    auto a = input<int>() - 1, b = input<int>() - 1;
    if (a == -1) {
      Q.emplace(u);
      vis[u] = true;
    }
    else {
      G.add_edge(a, u);
      G.add_edge(b, u);
    }
  }
  while (!Q.empty()) {
    auto u = Q.front();
    Q.pop();
    for (auto e: G[u]) {
      if (!vis[e.to]) {
        vis[e.to] = true;
        Q.emplace(e.to);
      }
    }
  }
  output(ranges::count(vis, true));
}
