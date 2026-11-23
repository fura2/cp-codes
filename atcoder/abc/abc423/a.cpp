#include "template/template.hpp"

// #define MULTI_TESTCASE
#include "template/main.hpp"

void testcase() {
  auto x = input<int>(), c = input<int>();
  int ans = 0;
  rep (i, x / 1000 + 1) {
    if ((1000 + c) * i <= x) ans = 1000 * i;
  }
  output(ans);
}
