#include "template/template.hpp"

// #define MULTI_TESTCASE
#include "template/main.hpp"

void testcase() {
  auto n = input<int>();
  auto p = input<vector<int>>(n, 1);

  lint ans = 0;
  rep (i, n) ans += abs(i - p[i]);
  output(ans / 2);
}
