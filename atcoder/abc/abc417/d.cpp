#include "template/template.hpp"

// #define MULTI_TESTCASE
#include "template/main.hpp"

void testcase() {
  auto n = input<int>();
  vector<int> p(n), a(n), b(n);
  rep (i, n) {
    p[i] = input<int>();
    a[i] = input<int>();
    b[i] = input<int>();
  }

  vector<int> cum(n + 1);
  rep (i, n) cum[i + 1] = cum[i] + b[i];

  vector dp(n + 1, vector(1001, -1));
  rep (x, 1001) dp[n][x] = x;
  rrep (i, n) {
    rep (x, 1001) {
      if (x <= p[i]) {
        dp[i][x] = dp[i + 1][x + a[i]];
      }
      else {
        dp[i][x] = dp[i + 1][max(x - b[i], 0)];
      }
    }
  }

  auto q = input<int>();
  rep (_, q) {
    auto x = input<int>();
    if (x <= 1000) {
      output(dp[0][x]);
    }
    else if (x - cum[n] > 1000) {
      output(x - cum[n]);
    }
    else {
      int lo = 0, hi = n;
      while (hi - lo > 1) {
        int mi = (lo + hi) / 2;
        (x - cum[mi] <= 1000 ? hi : lo) = mi;
      }
      output(dp[hi][x - cum[hi]]);
    }
  }
}
