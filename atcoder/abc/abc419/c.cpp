#include "template/template.hpp"

// #define MULTI_TESTCASE
#include "template/main.hpp"

void testcase() {
  auto n = input<int>();
  vector<int> r(n), c(n);
  rep (i, n) {
    r[i] = input<int>();
    c[i] = input<int>();
  }
  ranges::sort(r);
  ranges::sort(c);
  output(max((r[n - 1] - r[0] + 1) / 2, (c[n - 1] - c[0] + 1) / 2));
}
