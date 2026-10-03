#include "template/template.hpp"

// #define MULTI_TESTCASE
#include "template/main.hpp"

void testcase() {
  auto n = input<int>(), v = input<int>();
  auto a = input<vector<int>>(n);

  int ans = 0;
  rep (i, n) {
    rep (j, i + 1, n) {
      rep (k, j + 1, n) {
        if (i + j + k + 3 <= v) chmax(ans, a[i] + a[j] + a[k]);
      }
    }
  }
  output(ans);
}
