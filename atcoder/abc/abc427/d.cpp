#include "template/template.hpp"

#define MULTI_TESTCASE
#include "graph/digraph.hpp"
#include "template/main.hpp"

void testcase() {
  auto n = input<int>(), m = input<int>(), k = input<int>();
  auto s = input<string>();
  auto G = input<Digraph>(n, m, 1);
  vector dp(2 * k + 1, vector(n, false));  // true <=> 手番プレイヤーの必勝
  rep (u, n) dp[0][u] = (s[u] == 'A');
  rep (i, 1, 2 * k + 1) {
    rep (u, n) {
      for (const auto& e: G[u]) {
        if (!dp[i - 1][e.to]) {
          dp[i][u] = true;
        }
      }
    }
  }
  alicebob(dp[2 * k][0]);
}
