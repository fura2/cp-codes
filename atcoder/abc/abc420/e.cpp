#include "template/template.hpp"

// #define MULTI_TESTCASE
#include "algebra/collection/add_monoid.hpp"
#include "data_structure/aggregate_union_find.hpp"
#include "template/main.hpp"

void testcase() {
  auto n = input<int>(), q = input<int>();

  vector<int> color(n);
  AggregateUnionFind<AddMonoid<int>> U(n);
  rep (_, q) {
    auto t = input<int>(), u = input<int>() - 1;
    if (t == 1) {
      auto v = input<int>() - 1;
      U.unite(u, v);
    }
    else if (t == 2) {
      if (color[u] == 0) {
        color[u] = 1;
        U.set(u, U.get(u).unwrap() + 1);
      }
      else {
        color[u] = 0;
        U.set(u, U.get(u).unwrap() - 1);
      }
    }
    else {
      yesno(U.get(u).unwrap() > 0);
    }
  }
}
