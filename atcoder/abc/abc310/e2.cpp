// 解き直し

#include "template/template.hpp"

// #define MULTI_TESTCASE
#include "template/main.hpp"

int nand(int a, int b) {
  return !(a & b);
}

void testcase() {
  // int n = 6;
  // rep (S, 1 << n) {
  //   int x = bit(S, 0);
  //   rep (i, 1, n) x = nand(x, bit(S, i));
  //   string s;
  //   rep (i, n) s += bit(S, i) + '0';
  //   show(s, x);
  // }

  auto n = input<int>();
  auto s = input<string>();

  vector dp(2, vector<lint>(n + 1));
  rep (i, n) {
    int b = s[i] - '0';
    dp[b][i + 1]++;
    rep (c, 2) dp[nand(c, b)][i + 1] += dp[c][i];
  }

  output(ranges::fold_left(dp[1], 0LL, plus{}));
}
