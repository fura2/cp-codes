#include "template/template.hpp"

// #define MULTI_TESTCASE
#include "template/main.hpp"

void testcase() {
  auto n = input<int>(), p = input<int>();
  auto a = input<vector<int>>(n);

  int l = n, r = -1;
  rep (i, n) {
    if (a[i] == 0) {
      chmin(l, i);
      chmax(r, i);
    }
  }
  int ans = 0;
  if (l + 1 <= p) {
    ans += count(a.begin() + l + 1, a.begin() + p, 1) + (p - l);
  }
  if (p <= r) {
    ans += count(a.begin() + p, a.begin() + r, 1) + (r - p + 1);
  }
  output(ans);
}
