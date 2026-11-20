#include "template/template.hpp"

// #define MULTI_TESTCASE
#include "template/main.hpp"

void testcase() {
  auto n = input<int>(), m = input<int>();
  auto s = input<string>(), t = input<string>();

  vector<int> cum(n + 1);
  rep (i, m) {
    auto l = input<int>() - 1, r = input<int>();
    cum[l] = (cum[l] + 1) % 2;
    cum[r] = (cum[r] + 1) % 2;
  }
  rep (i, n) cum[i + 1] = (cum[i + 1] + cum[i]) % 2;

  rep (i, n)
    if (cum[i] == 1) swap(s[i], t[i]);
  output(s);
}
