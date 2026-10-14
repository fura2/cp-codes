#include "template/template.hpp"

// #define MULTI_TESTCASE
#include "algebra/collection/sum_assign_monoid_action.hpp"
#include "data_structure/lazy_segment_tree.hpp"
#include "template/main.hpp"

void testcase() {
  auto n = input<lint>();
  auto a = input<vector<int>>(n);

  vector pos(n + 1, vector<int>());
  rep (i, n) pos[a[i]].emplace_back(i);
  rep (k, n + 1) pos[k].emplace_back(n);  // sentinel

  vector<pair<lint, int>> data(n);
  rep (i, n) data[i] = {i, 1};
  LazySegmentTree<SumAssignMonoidAction<lint>> S(data);

  vector<lint> f(n + 2);
  rep (k, n + 1) {
    f[k] = n * n - S.fold().first.unwrap();

    int pre = 0;
    for (int i: pos[k]) {
      if (pre < n && S.get(pre).first.unwrap() < i) {
        int lo = pre, hi = i;
        while (hi - lo > 1) {
          int mi = (lo + hi) / 2;
          (S.get(mi).first.unwrap() >= i ? hi : lo) = mi;
        }
        S.apply(pre, hi, i);
      }
      pre = i + 1;
    }
  }
  output(reduce(f.begin() + 1, f.end()));
}
