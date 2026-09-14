#include "template/template.hpp"

// #define MULTI_TESTCASE
#include "template/main.hpp"

void testcase() {
  auto n = input<int>();
  int ans[3] = {};
  rep (i, n) {
    int a = input<int>();
    int r = (a + 999) / 1000 * 1000 - a;
    ans[0] += r % 10;
    ans[1] += r % 100 / 10;
    ans[2] += r % 1000 / 100;
  }
  output(ans);
}
