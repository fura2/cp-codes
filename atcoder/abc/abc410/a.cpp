#include "template/template.hpp"

// #define MULTI_TESTCASE
#include "template/main.hpp"

void testcase() {
  auto n = input<int>();
  auto a = input<vector<int>>(n);
  auto k = input<int>();

  int ans = 0;
  rep (i, n)
    if (k <= a[i]) ans++;
  output(ans);
}
