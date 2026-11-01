#include "template/template.hpp"

// #define MULTI_TESTCASE
#include "template/main.hpp"

void testcase() {
  auto n = input<int>();
  auto x = input<vector<lint>>(n);

  if (n == 1) {
    output(0);
    return;
  }

  vector<lint> ans(n, LINF);
  rep (i, n) {
    // 左に動く
    if (i > 0) {
      chmin(ans[i],
            (x[i] - x[i - 1]) / 2 +
                max((x[n - 1] - x[i]) / 2, (x[i - 1] - x[0]) / 2));
    }
    // 右に動く
    if (i < n - 1) {
      chmin(ans[i],
            (x[i + 1] - x[i]) / 2 +
                max((x[i] - x[0]) / 2, (x[n - 1] - x[i + 1]) / 2));
    }
  }
  output(ans);
}
