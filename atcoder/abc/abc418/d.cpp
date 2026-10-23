#include "template/template.hpp"

// #define MULTI_TESTCASE
#include "template/main.hpp"

void testcase() {
  auto n = input<int>();
  auto s = input<string>();

  lint ans = 0;
  map<pair<int, int>, int> h;  // (sum mod 2, len mod 2) -> count
  h[{0, 0}] = 1;
  int x = 0;
  rep (i, n) {
    x ^= s[i] - '0';
    ans += h[{x ^ 1, i % 2}] + h[{x, (i + 1) % 2}];
    ++h[{x, (i + 1) % 2}];
  }
  output(ans);
}
