#include "template/template.hpp"

// #define MULTI_TESTCASE
#include "algebra/collection/argmax_monoid.hpp"
#include "algebra/collection/argmin_monoid.hpp"
#include "data_structure/segment_tree.hpp"
#include "template/main.hpp"

void testcase() {
  auto n = input<int>(), q = input<int>();
  auto p = input<vector<int>>(n, 1);

  SegmentTree<IntArgminMonoid> S_min(n);
  SegmentTree<IntArgmaxMonoid> S_max(n);
  rep (i, n) {
    S_min.set(i, pair{p[i], i});
    S_max.set(i, pair{p[i], i});
  }
  rep (_, q) {
    auto l = input<int>() - 1, r = input<int>();
    auto i_min = S_min.fold(l, r).unwrap().second;
    auto i_max = S_max.fold(l, r).unwrap().second;
    S_min.set(i_min, pair{p[i_max], i_min});
    S_min.set(i_max, pair{p[i_min], i_max});
    S_max.set(i_min, pair{p[i_max], i_min});
    S_max.set(i_max, pair{p[i_min], i_max});
    swap(p[i_min], p[i_max]);
  }
  output(p, 1);
}
