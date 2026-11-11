#include "template/template.hpp"

// #define MULTI_TESTCASE
#include "template/main.hpp"

void testcase() {
  auto x = input<int>(), y = input<int>();
  int ans = 0;
  rep (i, 1, 7)
    rep (j, 1, 7)
      if (i + j >= x || abs(i - j) >= y) ans++;
  output(ans / 36.0);
}
