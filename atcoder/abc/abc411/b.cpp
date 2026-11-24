#include "template/template.hpp"

// #define MULTI_TESTCASE
#include "template/main.hpp"

void testcase() {
  auto n = input<int>();
  auto d = input<vector<int>>(n - 1);
  rep (i, n) {
    rep (j, i + 1, n) {
      int ans = 0;
      rep (k, i, j) ans += d[k];
      output(ans);
    }
  }
}
