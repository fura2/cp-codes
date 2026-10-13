// 解き直し

#include "template/template.hpp"

#include <ranges>

// #define MULTI_TESTCASE
#include "mint/mod_int.hpp"
#include "template/main.hpp"

using mint = ModInt<int(1e9 + 7)>;

void testcase() {
  auto n = input<int>();
  auto s = input<string>();

  if (set(from_range, s).size() == 1) {
    output(1);
    return;
  }

  vector<int> a(n);
  rep (i, n) a[i] = s[i] - 'A' + 1;

  vector<int> cum(n + 1);
  rep (i, n) cum[i + 1] = cum[i] ^ a[i];

  // // naive
  // // dp[i] = (S[0,i) を suffix xor が常に非 0 であるような
  // //          ブロックに分割する方法の数)
  // vector<mint> dp(n + 1); dp[0] = 1;
  // rep (i, n) {
  //   int p;
  //   for (p = i; p >= 0; p--)
  //     if (cum[p] == cum[i + 1]) break;
  //   rep (j, p + 1, i + 1) dp[i + 1] += dp[j];
  // }

  // mint ans = 0;
  // rep (i, n)
  //   if (cum[i + 1] == cum[n]) ans += dp[i + 1];
  // output(ans);

  // dp[i] = 上の dp の累積和
  vector<mint> dp(n + 2);
  dp[1] = 1;
  vector<int> pos(4, -1);
  rep (i, n) {
    pos[cum[i]] = i;
    int p = pos[cum[i + 1]];
    dp[i + 2] = dp[i + 1] + (dp[i + 1] - dp[p + 1]);
  }

  mint ans = 0;
  rep (i, n)
    if (cum[i + 1] == cum[n]) ans += dp[i + 2] - dp[i + 1];
  output(ans);
}
