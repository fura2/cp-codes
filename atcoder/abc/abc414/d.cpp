#include "template/template.hpp"

// #define MULTI_TESTCASE
#include "template/main.hpp"

void testcase() {
  auto n = input<int>(), m = input<int>();
  auto x = input<vector<lint>>(n);
  ranges::sort(x);

  vector<lint> d(n - 1);
  rep (i, n - 1) d[i] = x[i + 1] - x[i];
  ranges::sort(d, greater{});

  lint ans = x[n - 1] - x[0];
  rep (i, m - 1) ans -= d[i];
  output(ans);
}
