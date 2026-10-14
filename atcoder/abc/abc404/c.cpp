#include "template/template.hpp"

// #define MULTI_TESTCASE
#include "graph/connected_components.hpp"
#include "graph/graph.hpp"
#include "template/main.hpp"

void testcase() {
  auto n = input<int>(), m = input<int>();
  auto G = input<Graph>(n, m, 1);

  bool ok = connected_components(G).size() == 1;
  rep (u, n)
    if (G.degree(u) != 2) ok = false;
  yesno(ok);
}
