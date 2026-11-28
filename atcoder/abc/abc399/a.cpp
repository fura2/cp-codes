#include "template/template.hpp"

// #define MULTI_TESTCASE
#include "template/main.hpp"

void testcase() {
  auto n = input<int>();
  auto s = input<string>(), t = input<string>();

  int ans = 0;
  rep (i, n)
    if (s[i] != t[i]) ans++;
  output(ans);
}
