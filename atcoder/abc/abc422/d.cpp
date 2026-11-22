#include "template/template.hpp"

// #define MULTI_TESTCASE
#include "template/main.hpp"

// m (<2^n) 個の 1, 2^n-m 個の 0 からなる数列に対する
// 最小コストとそれを達成する数列
pair<int, vector<int>> f(int n, int m) {
  if (m == 0) {
    return {0, vector<int>(1 << n)};
  }

  vector<int> res(1 << n);
  if (m >= (1 << (n - 1))) {
    rep (i, 1 << (n - 1)) res[2 * i] = 1;
    m -= 1 << (n - 1);
  }
  auto [c, r] = f(n - 1, m);
  rep (i, 1 << (n - 1)) res[2 * i + 1] = r[i];
  return {max(1, c), res};
}

void testcase() {
  auto n = input<int>();
  auto k = input<int>();

  auto [cost, ans] = f(n, k % (1 << n));
  rep (i, 1 << n) ans[i] += k / (1 << n);

  output(cost);
  output(ans);
}
