#include "template/template.hpp"

// #define MULTI_TESTCASE
#include "graph/strongly_connected_components.hpp"
#include "graph/weighted_digraph.hpp"
#include "template/main.hpp"

void testcase() {
  auto n = input<int>(), q = input<int>();
  WeightedDigraph<int> G(n, q);
  rep (i, q) {
    auto t = input<int>(), u = input<int>() - 1, v = input<int>() - 1;
    G.add_edge(u, v, t);
  }

  StronglyConnectedComponents scc(G);
  rep (u, n) {
    for (const auto& e: G[u]) {
      if (scc.component_id(u) == scc.component_id(e.to) && e.cost == 1) {
        no();
        return;
      }
    }
  }

  auto D = scc.condensation();
  vector<int> res(scc.size(), 1);
  rep (i, scc.size()) {
    for (const auto& e: D[i]) {
      for (int id: scc.edges(i, e.to)) {
        chmax(res[e.to], res[i] + G.edge(id).cost);
      }
    }
  }
  vector<int> ans(n);
  rep (u, n) ans[u] = res[scc.component_id(u)];
  yes();
  output(ans);
}
