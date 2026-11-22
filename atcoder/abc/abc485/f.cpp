#include "template/template.hpp"

// #define MULTI_TESTCASE
#include "template/main.hpp"

void testcase() {
  auto n = input<int>(), m = input<int>();
  vector<int> c(n);
  vector<lint> v(n);
  rep (i, n) {
    c[i] = input<int>();
    v[i] = input<lint>();
  }

  vector<lint> ans(m + 1);
  vector dp(n + 1, deque(m + 1, -LINF));
  rep (x, m + 1) dp[0][x] = 0;
  rrep (j, m + 1) {
    lint zero = 0;
    rep (k, n)
      if (c[k] <= j) zero += v[k];

    rep (k, n) {
      if (c[k] - j != 1) continue;
      rrep (i, n) {
        rep (x, m) {
          if (dp[i][x] != -LINF) {
            chmax(dp[i + 1][x + 1], dp[i][x] + v[k]);
          }
        }
      }
      rep (i, n + 1) {
        rep (x, m) chmax(dp[i][x + 1], dp[i][x]);
      }
    }

    lint res = 0;
    rep (i, n + 1) chmax(res, dp[i][m]);
    ans[j] = zero + res;

    rep (i, n + 1) {
      rep (_, i) {
        dp[i].pop_back();
        dp[i].emplace_front(-LINF);
      }
    }
  }

  output(ans);
}
