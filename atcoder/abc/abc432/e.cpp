#include "template/template.hpp"

// #define MULTI_TESTCASE
#include "algebra/collection/add_group.hpp"
#include "data_structure/fenwick_tree.hpp"
#include "template/main.hpp"

void testcase() {
  auto n = input<int>(), q = input<int>();
  auto a = input<vector<int>>(n);

  int m = 5e5 + 1;
  FenwickTree<LintAddGroup> F1(m), F2(m);
  rep (i, n) {
    F1.apply(a[i], a[i]);
    F2.apply(a[i], 1);
  }

  rep (_, q) {
    auto t = input<int>();
    if (t == 1) {
      auto x = input<int>() - 1, y = input<int>();
      F1.apply(a[x], -a[x]);
      F2.apply(a[x], -1);
      a[x] = y;
      F1.apply(a[x], a[x]);
      F2.apply(a[x], 1);
    }
    else {
      auto l = input<int>(), r = input<int>();
      if (l >= r) {
        output(lint{n} * l);
      }
      else {
        output(l * F2.fold(0, l).unwrap() + F1.fold(l, r + 1).unwrap() +
               r * F2.fold(r + 1, m).unwrap());
      }
    }
  }
}
