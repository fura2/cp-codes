#include "template/template.hpp"

// #define MULTI_TESTCASE
#include "template/main.hpp"

void testcase() {
  auto n = input<int>();
  auto a = input<vector<int>>(n);

  vector<int> ans(a[0]);
  int h = n;
  rep (j, a[0]) {
    while (a[h - 1] < j + 1) h--;
    ans[j] = h;
  }
  output(ans);
}
