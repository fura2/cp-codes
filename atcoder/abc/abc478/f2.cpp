#include "template/template.hpp"

// #define MULTI_TESTCASE
#include "algebra/collection/max_monoid.hpp"
#include "data_structure/segment_tree.hpp"
#include "mint/mint.hpp"
#include "template/main.hpp"

void testcase() {
  auto n = input<int>();
  auto p = input<vector<int>>(n, 1);

  mint ans = 1;
  SegmentTree<MaxMonoid<int>> S(p);
  rep (i, 1, n) {
    int j = S.min_left(
        i, [&](const MaxMonoid<int>& m) { return m.unwrap() <= p[i]; });
    if (j > 0) j--;
    ans *= i - j;
  }
  output(ans);
}
