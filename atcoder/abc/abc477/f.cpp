#include "template/template.hpp"

// #define MULTI_TESTCASE
#include "algebra/collection/add_add_pair_group.hpp"
#include "algebra/collection/add_group.hpp"
#include "algebra/monoid_action_impl.hpp"
#include "algebra/pair_group.hpp"
#include "data_structure/lazy_segment_tree.hpp"
#include "template/main.hpp"

using A = MonoidActionImpl<
    LintAddLintAddPairGroup,
    LintAddGroup,
    [](const LintAddLintAddPairGroup& m, const LintAddGroup& f) {
      return LintAddLintAddPairGroup{
          m.first.unwrap() + m.second.unwrap() * f.unwrap(), m.second};
    }>;

void testcase() {
  auto h = input<int>(), w = input<int>(), q = input<int>();
  vector<int> l(h), r(h);
  rep (i, h) {
    l[i] = input<int>() - 1;
    r[i] = input<int>();
  }

  vector<int> a(q), b(q), c(q), d(q);
  rep (i, q) {
    a[i] = input<int>() - 1;
    c[i] = input<int>();
    b[i] = input<int>() - 1;
    d[i] = input<int>();
  }

  vector<pair<int, int>> Ev;
  rep (i, q) {
    Ev.emplace_back(a[i], b[i]);
    Ev.emplace_back(a[i], d[i]);
    Ev.emplace_back(c[i], b[i]);
    Ev.emplace_back(c[i], d[i]);
  }
  ranges::sort(Ev);

  vector<LintAddLintAddPairGroup> data(w);
  rep (i, w) data[i] = {0, 1};
  LazySegmentTree<A> S(data);

  map<pair<int, int>, lint> res;
  int i_pre = 0;
  for (auto [i, j]: Ev) {
    if (res.contains({i, j})) continue;
    while (i > i_pre) {
      S.apply(l[i_pre], r[i_pre], 1);
      show(l[i_pre], r[i_pre]);
      i_pre++;
    }
    res[{i, j}] = S.fold(0, j).first.unwrap();
  }

  rep (i, q) {
    output(res[{c[i], d[i]}] - res[{c[i], b[i]}] - res[{a[i], d[i]}] +
           res[{a[i], b[i]}]);
  }
}
