#include "template/template.hpp"

// #define MULTI_TESTCASE
#include "template/main.hpp"

void testcase() {
  auto n = input<int>();
  auto a = input<vector<int>>(n);
  int ans = 0;
  rep (i, 0, n, 2) ans += a[i];
  output(ans);
}
