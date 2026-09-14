#include "template/template.hpp"

#define MULTI_TESTCASE
#include "data_structure/union_find.hpp"
#include "graph/weighted_edge.hpp"
#include "graph/weighted_graph.hpp"
#include "template/main.hpp"

void testcase() {
  auto n = input<int>();
  auto m = input<int>();
  auto k = input<int>();
  auto G = input<WeightedGraph<int>>(n, m, 1);

  set<int> E0, E1;  // edges with cost 0/1
  UnionFind U(n);
  vector<int> p(m);
  ranges::iota(p, 0);
  ranges::sort(p,
               [&](int i, int j) { return G.edge(i).cost < G.edge(j).cost; });
  for (int i: p) {
    const auto& e = G.edge(i);
    if (!U.same(e.from, e.to)) {
      U.unite(e.from, e.to);
      if (e.cost == 1) E1.emplace(i);
    }
  }

  U = UnionFind(n);
  for (int i: E1) {
    const auto& e = G.edge(i);
    U.unite(e.from, e.to);
  }

  ranges::reverse(p);
  for (int i: p) {
    const auto& e = G.edge(i);
    if (!U.same(e.from, e.to) && E1.size() + e.cost <= k) {
      U.unite(e.from, e.to);
      (e.cost == 0 ? E0 : E1).emplace(i);
    }
  }

  if (E1.size() != k)
    output(-1);
  else {
    output(vector(from_range, E0), 1);
    output(vector(from_range, E1), 1);
  }
}
