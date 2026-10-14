#include "template/template.hpp"

// #define MULTI_TESTCASE
#include "template/main.hpp"
#include "util/grid.hpp"

void testcase() {
  auto n = input<int>();
  auto A = input<Grid>(n), B = input<Grid>(n);

  int ans = INF;
  rep (k, 4) {
    int cnt = (4 - k) % 4;
    rep (i, n)
      rep (j, n)
        if (A[i][j] != B[i][j]) cnt++;
    chmin(ans, cnt);
    A = A.rotate();
  }
  output(ans);
}
