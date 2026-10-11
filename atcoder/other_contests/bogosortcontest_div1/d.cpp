#include "template/template.hpp"

#define MULTI_TESTCASE
#include "template/main.hpp"

void testcase() {
  auto n = input<int>();
  auto k = input<lint>();
  vector<vector<pair<int, int>>> from(n);
  rep (i, n - 1) {
    auto l = input<int>() - 1, r = input<int>() - 1;
    from[l].emplace_back(i, 0);
    from[r].emplace_back(i, 1);
  }

  vector<lint> dp(n);  // dp[u] = (頂点 u が踏まれた回数)
  dp[0] = k;
  rep (u, 1, n) {
    for (auto [p, c]: from[u]) {
      if (c == 0) {  // l edge
        dp[u] += dp[p] / 2;
      }
      else {  // r edge
        dp[u] += (dp[p] + 1) / 2;
      }
    }
  }
  output(accumulate(dp.begin(), dp.end() - 1, 0LL));
}
