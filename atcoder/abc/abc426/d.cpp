#include "template/template.hpp"

#define MULTI_TESTCASE
#include "string/run_length_encoding.hpp"
#include "template/main.hpp"

int solve(string s) {
  vector<int> zero = {0}, one;
  for (auto [c, k]: run_length_encoding(s)) {
    (c == '0' ? zero : one).emplace_back(k);
  }

  return 2 * (ranges::fold_left(zero, 0, plus{}) - ranges::max(zero)) +
         ranges::fold_left(one, 0, plus{});
}

void testcase() {
  auto n = input<int>();
  auto s = input<string>();

  int ans = INF;
  rep (_, 2) {
    chmin(ans, solve(s));
    rep (i, n) s[i] = '1' - s[i] + '0';
  }
  output(ans);
}
