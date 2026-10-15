#include "template/template.hpp"

// #define MULTI_TESTCASE
#include "template/main.hpp"

void testcase() {
  auto s = input<int>(), a = input<int>(), b = input<int>(), x = input<int>();
  int ans = 0;
  rep (t, x)
    if (t % (a + b) < a) ans += s;
  output(ans);
}
