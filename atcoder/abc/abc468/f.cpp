#include "template/template.hpp"

// #define MULTI_TESTCASE
#include "algebra/collection/max_add_monoid_action.hpp"
#include "data_structure/lazy_segment_tree.hpp"
#include "template/main.hpp"

void testcase() {
  auto n = input<int>();
  auto p = input<vector<int>>(n);

  LazySegmentTree<MaxAddMonoidAction<int>> dp(n + 1);
  dp.set(0, 1);
  int mx = p[0];
  rep (i, 1, n) {
    if (p[i] > mx) {
      dp.apply(0, n + 1, 1);
      mx = p[i];
    }
    else {
      int val = dp.fold(0, p[i]).unwrap();
      if (val + 1 > dp.get(p[i]).unwrap()) {
        dp.set(p[i], val + 1);
      }
    }
  }
  output(dp.fold(0, n + 1).unwrap());
}
