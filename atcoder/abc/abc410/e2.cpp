#include "template/template.hpp"

// #define MULTI_TESTCASE
#include "template/main.hpp"

void testcase() {
  auto n = input<int>(), h = input<int>(), m = input<int>();
  vector<int> a(n), b(n);
  rep (i, n) {
    a[i] = input<int>();
    b[i] = input<int>();
  }

  int ans = 0;
  vector<int> dp(h + 1, -INF), ndp(h + 1);  // 残り体力 -> 残り魔力の max
  dp[h] = m;
  rep (i, n) {
    ranges::fill(ndp, -INF);
    rep (x, h + 1) {
      if (dp[x] == -INF) continue;
      if (x >= a[i]) {
        chmax(ndp[x - a[i]], dp[x]);
      }
      if (dp[x] >= b[i]) {
        chmax(ndp[x], dp[x] - b[i]);
      }
    }
    if (ranges::max(ndp) >= 0) ans = i + 1;
    swap(dp, ndp);
  }
  output(ans);
}
