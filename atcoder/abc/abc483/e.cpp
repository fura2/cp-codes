#include "template/template.hpp"

// #define MULTI_TESTCASE
#include "template/main.hpp"

void testcase() {
  auto n = input<int>(), m = input<int>();
  auto s = input<vector<string>>(n);

  lint ans = 0;
  vector<string> t(n);
  rep (S, 1 << m) {
    int pc = popcount(uint(S));
    if (pc > 2) continue;

    rep (i, n) {
      t[i] = s[i];
      rep (j, m)
        if (bit(S, j) == 1) t[i][j] = '?';
    }

    lint cnt = 0;
    unordered_map<string, int> h;
    rep (i, n) {
      cnt += h[t[i]]++;
    }
    if (pc == 2) {
      ans += cnt;
    }
    else if (pc == 1) {
      ans -= (m - 2) * cnt;
    }
    else if (pc == 0) {
      ans += (m - 1) * (m - 2) / 2 * cnt;
    }
  }
  output(ans);
}
