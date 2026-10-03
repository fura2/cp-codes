#include "template/template.hpp"

// #define MULTI_TESTCASE
#include "template/main.hpp"

void testcase() {
  auto n = input<int>(), m = input<int>();
  vector<int> ans(n);
  rep (i, m) ans[i % n]++;
  output(ans);
}
