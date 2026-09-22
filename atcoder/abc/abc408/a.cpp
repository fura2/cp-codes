#include "template/template.hpp"

// #define MULTI_TESTCASE
#include "template/main.hpp"

void testcase() {
  auto n = input<int>(), s = input<int>();
  int pre = 0;
  rep (i, n) {
    auto t = input<int>();
    if (t - pre > s) {
      no();
      return;
    }
    pre = t;
  }
  yes();
}
