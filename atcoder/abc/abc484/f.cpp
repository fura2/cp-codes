#include "template/template.hpp"

// #define MULTI_TESTCASE
#include "algebra/monoid_impl.hpp"
#include "data_structure/segment_tree.hpp"
#include "template/main.hpp"

using M =
    MonoidImpl<tuple<int, int, int>,
               [](const tuple<int, int, int>& a,
                  const tuple<int, int, int>& b) {
                 auto [amin, amax, acnt] = a;
                 auto [bmin, bmax, bcnt] = b;
                 return tuple{min(amin, bmin), max(amax, bmax), acnt + bcnt};
               },
               []() { return tuple{INF, -INF, 0}; }>;

void testcase() {
  auto n = input<int>(), q = input<int>();
  auto a = input<vector<int>>(n);

  SegmentTree<M> S(n);
  auto set = [&](int i, int v) {
    if (v == -1) {
      S.set(i, tuple{INF, -INF, 1});
    }
    else {
      S.set(i, tuple{v, v, 0});
    }
  };
  rep (i, n) set(i, a[i]);
  rep (_, q) {
    int t = input<int>();
    if (t == 1) {
      auto i = input<int>() - 1, x = input<int>();
      a[i] = x;
      set(i, a[i]);
    }
    else {
      auto l = input<int>() - 1, r = input<int>();
      auto [rmin, rmax, rcnt] = S.fold(l, r).unwrap();
      yesno(rcnt == r - l || rmin == rmax);
    }
  }
}
