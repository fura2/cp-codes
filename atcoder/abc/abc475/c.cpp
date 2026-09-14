#include "template/template.hpp"

// #define MULTI_TESTCASE
#include "template/main.hpp"

void testcase() {
  auto n = input<int>(), s = input<int>() - 1;
  auto l = input<lint>();
  auto a = input<vector<lint>>(n - 1);

  vector<lint> cum(n);
  rep (i, n - 1) cum[i + 1] = cum[i] + a[i];

  int ans = 0;
  rep (i, 0, s + 1) {
    rep (j, s, n) {
      lint x = cum[s] - cum[i];
      lint y = cum[j] - cum[s];
      if (x + y + min(x, y) <= l) {
        chmax(ans, j - i + 1);
      }
    }
  }
  output(ans);
}
