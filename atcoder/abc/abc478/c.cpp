#include "template/template.hpp"

// #define MULTI_TESTCASE
#include "template/main.hpp"

void testcase() {
  auto n = input<int>(), k = input<int>();
  auto a = input<vector<int>>(n);

  auto b = a;
  ranges::sort(b);
  if (a == b) {
    yes();
    return;
  }

  int l = n, r = 0;
  rep (i, n) {
    if (a[i] != b[i]) {
      chmin(l, i);
      chmax(r, i);
    }
  }
  yesno(r - l + 1 <= k);
}
