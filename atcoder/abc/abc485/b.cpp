#include "template/template.hpp"

// #define MULTI_TESTCASE
#include "template/main.hpp"

void testcase() {
  auto n = input<int>(), m = input<int>();
  auto s = input<vector<string>>(n);

  rep (i, n) {
    if (ranges::count(s[i], 'x') == m) {
      output("Faucet " + to_string(i + 1));
      return;
    }
  }
  rep (j, m) {
    int cnt = 0;
    rep (i, n)
      if (s[i][j] == 'x') cnt++;
    if (cnt == n) {
      output("Drain " + to_string(j + 1));
      return;
    }
  }
}
