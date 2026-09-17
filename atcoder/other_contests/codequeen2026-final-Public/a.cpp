#include "template/template.hpp"

// #define MULTI_TESTCASE
#include "template/main.hpp"

void testcase() {
  auto n = input<int>(), x = input<int>();
  int ans = -1;
  rep (i, n) {
    auto c = input<int>(), a = input<int>();
    if (c == x) chmax(ans, a);
  }
  output(ans);
}
