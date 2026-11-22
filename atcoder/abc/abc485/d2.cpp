#include "template/template.hpp"

// #define MULTI_TESTCASE
#include "template/main.hpp"

void testcase() {
  auto n = input<int>();
  auto s = input<string>();

  vector dp(n + 1, vector(3, vector(8, 0LL)));
  dp[0][0][0] = 1;
  rep (i, n) {
    int c = s[i] - 'A';
    rep (t, 3) {
      rep (S, 8) {
        dp[i + 1][t][S | (1 << c)] += dp[i][t][S];
      }
      if (t < 2) {
        dp[i + 1][t + 1][1 << c] += dp[i][t][7];
      }
    }
  }
  output(dp[n][2][7]);
}
