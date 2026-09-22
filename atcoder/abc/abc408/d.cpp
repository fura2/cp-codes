#include "template/template.hpp"

#define MULTI_TESTCASE
#include "template/main.hpp"

void testcase() {
  auto n = input<int>();
  auto s = input<string>();

  vector dp(3, vector(n + 1, INF));
  dp[0][0] = 0;
  rep (i, n) {
    chmin(dp[0][i + 1], dp[0][i] + (s[i] == '0' ? 0 : 1));
    chmin(dp[1][i + 1], dp[0][i] + (s[i] == '1' ? 0 : 1));
    chmin(dp[1][i + 1], dp[1][i] + (s[i] == '1' ? 0 : 1));
    chmin(dp[2][i + 1], dp[1][i] + (s[i] == '0' ? 0 : 1));
    chmin(dp[2][i + 1], dp[2][i] + (s[i] == '0' ? 0 : 1));
  }
  output(min({dp[0][n], dp[1][n], dp[2][n]}));
}
