#include "template/template.hpp"

#include <algorithm>

#define MULTI_TESTCASE
#include "mint/binomial_range_sum.hpp"
#include "mint/mint.hpp"
#include "template/main.hpp"

void testcase() {
  auto n = input<int>();
  auto k = input<int>();
  auto a = input<vector<lint>>(n);

  ranges::reverse(a);

  lint mx = ranges::fold_left(a.begin(), a.begin() + k, 0LL, bit_or{});

  BinomialRangeSum<mint> brs(n, 0, k);

  mint ans = 0;
  if (mx == 0) ans += 1;  // 全部 AND
  rep (i, n) {
    if (k == 0) break;
    if ((mx & a[i]) != mx) {  // OR で一部確定
      k--;
      mx &= ~a[i];
    }
    else {  // OR で全部確定 or AND
      ans += brs.sum(n - i - 1, 0, k);
    }
  }
  output(ans);
}
