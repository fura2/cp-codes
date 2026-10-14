#include "template/template.hpp"

// #define MULTI_TESTCASE
#include "template/main.hpp"

void testcase() {
  auto n = input<int>(), m = input<int>();
  auto c = input<vector<lint>>(n);
  vector<int> A(m);
  rep (i, m) {
    auto k = input<int>();
    rep (_, k) {
      int j = input<int>() - 1;
      A[i] |= 1 << (2 * j);
      A[i] |= 1 << (2 * j + 1);
    }
  }

  lint ans = LINF;
  vector<int> cnt(n);
  rep (S, 1 << 2 * n) {
    bool ok = true;
    rep (i, m) {
      if (popcount<uint>(A[i] & S) < 2) {
        ok = false;
        break;
      }
    }
    if (!ok) continue;

    lint cost = 0;
    rep (i, 2 * n)
      if (bit(S, i)) cost += c[i / 2];
    chmin(ans, cost);
  }
  output(ans);
}
