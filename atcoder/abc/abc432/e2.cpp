#include "template/template.hpp"

// #define MULTI_TESTCASE
#include "algebra/collection/add_add_pair_group.hpp"
#include "data_structure/fenwick_tree.hpp"
#include "template/main.hpp"

void testcase() {
  auto n = input<int>(), q = input<int>();
  auto a = input<vector<int>>(n);

  int m = 5e5 + 1;
  FenwickTree<LintAddLintAddPairGroup> F(m);
  rep (i, n) F.apply(a[i], {1, a[i]});

  rep (_, q) {
    auto t = input<int>();
    if (t == 1) {
      auto x = input<int>() - 1, y = input<int>();
      F.apply(a[x], {-1, -a[x]});
      a[x] = y;
      F.apply(a[x], {1, a[x]});
    }
    else {
      auto l = input<int>(), r = input<int>();
      if (l >= r) {
        output(lint{n} * l);
      }
      else {
        output(l * F.fold(0, l).first.unwrap() +
               F.fold(l, r + 1).second.unwrap() +
               r * F.fold(r + 1, m).first.unwrap());
      }
    }
  }
}
