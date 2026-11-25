#include "template/template.hpp"

// #define MULTI_TESTCASE
#include "template/main.hpp"

void testcase() {
  auto n = input<int>();
  auto a = input<vector<int>>(n);

  int ans = 0;
  rep (x, n + 1) {
    int cnt = 0;
    rep (i, n)
      if (a[i] >= x) cnt++;
    if (cnt >= x) ans = x;
  }
  output(ans);
}
