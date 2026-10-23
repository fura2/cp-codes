#include "template/template.hpp"

// #define MULTI_TESTCASE
#include "template/main.hpp"

void testcase() {
  auto n = input<int>();
  auto a = input<vector<int>>(n);

  lint ans = 0;
  map<int, int> h;
  rep (i, n) {
    ans += h[i + 1 - a[i]];
    ++h[a[i] + i + 1];
  }
  output(ans);
}
