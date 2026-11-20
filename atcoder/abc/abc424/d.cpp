#include "template/template.hpp"

#define MULTI_TESTCASE
#include "template/main.hpp"
#include "util/grid.hpp"

void testcase() {
  auto h = input<int>(), w = input<int>();
  auto B = input<Grid>(h, w);

  vector<int> dp(1 << w, INF), ndp(1 << w, INF);
  dp[0] = 0;
  rep (i, h) {
    rep (S, 1 << w) ndp[S] = INF;

    rep (S, 1 << w) {
      if (dp[S] == INF) continue;
      rep (T, 1 << w) {
        bool ok = true;
        rep (j, w - 1) {
          if (bit(S, j) && bit(S, j + 1) && bit(T, j) && bit(T, j + 1))
            ok = false;
        }
        if (!ok) continue;
        int cost = 0;
        rep (j, w)
          if ((B[i][j] == '.' && bit(T, j) == 1) ||
              (B[i][j] == '#' && bit(T, j) == 0))
            cost++;
        chmin(ndp[T], dp[S] + cost);
      }
    }

    swap(dp, ndp);
  }
  output(ranges::min(dp));
}
