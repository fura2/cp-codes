#include "template/template.hpp"

// #define MULTI_TESTCASE
#include "template/main.hpp"

void testcase() {
  auto n = input<int>();
  int ans = 0;
  rep (i, 1, n + 1) ans += (i % 2 == 0 ? 1 : -1) * i * i * i;
  output(ans);
}
