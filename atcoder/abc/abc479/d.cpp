#include "template/template.hpp"

// #define MULTI_TESTCASE
#include "template/main.hpp"

void testcase() {
  auto n = input<int>(), q = input<int>();
  auto l = input<vector<lint>>(n - 1);
  auto r = input<vector<lint>>(n - 1);

  vector<lint> lmin(n), rmin(n);
  lmin[n - 1] = LINF;
  rrep (i, n - 1) lmin[i] = min(lmin[i + 1], l[i]);
  rmin[0] = LINF;
  rep (i, n - 1) rmin[i + 1] = min(rmin[i], r[i]);

  rep (_, q) {
    auto s = input<int>() - 1, t = input<int>() - 1;
    lint res = LINF;
    if (s < t) {
      res = r[s];
      if (s > 0) chmin(res, l[s - 1] + rmin[s]);
    }
    else {
      res = l[s - 1];
      if (s < n - 1) chmin(res, r[s] + lmin[s]);
    }
    output(res);
  }
}
