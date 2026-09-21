#include "template/template.hpp"

// #define MULTI_TESTCASE
#include "template/main.hpp"

void testcase() {
  auto n = input<int>();
  int ans = 0;
  rep (i, n) {
    auto a = input<int>(), b = input<int>();
    if (a < b) ans++;
  }
  output(ans);
}
