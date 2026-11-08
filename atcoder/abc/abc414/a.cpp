#include "template/template.hpp"

// #define MULTI_TESTCASE
#include "template/main.hpp"

void testcase() {
  auto n = input<int>(), l = input<int>(), r = input<int>();
  int ans = 0;
  rep (i, n) {
    auto x = input<int>(), y = input<int>();
    if (x <= l && r <= y) ans++;
  }
  output(ans);
}
