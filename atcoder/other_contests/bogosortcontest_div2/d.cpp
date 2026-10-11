#include "template/template.hpp"

#define MULTI_TESTCASE
#include "algebra/collection/max_monoid.hpp"
#include "algebra/collection/min_monoid.hpp"
#include "data_structure/segment_tree.hpp"
#include "template/main.hpp"

void testcase() {
  auto n = input<int>();
  auto s = input<string>();

  vector<int> a(2 * n);
  rep (i, n) {
    a[i] = a[n + i] = (s[i] == '1' ? 1 : -1);
  }
  vector<int> acum(2 * n + 1);
  rep (i, 2 * n) acum[i + 1] = acum[i] + a[i];

  vector<int> ans(n);
  SegmentTree<MinMonoid<int>> S_min{acum};
  SegmentTree<MaxMonoid<int>> S_max{acum};
  rep (i, n) {
    if (s[i] == '0') {
      ans[i] = i;
      continue;
    }

    int r = S_min.max_right(
        i + 1, [&](const MinMonoid<int>& m) { return m.unwrap() > acum[i]; });
    if (r > i + n) {
      int d = acum[i + n + 1] - acum[i + 1];
      r = S_max.max_right(i + 1, [&](const MaxMonoid<int>& m) {
        return m.unwrap() < acum[i] + d;
      });
    }
    ans[i] = (r - 1) % n;
  }
  output(ans, 1);
}
