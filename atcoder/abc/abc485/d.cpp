#include "template/template.hpp"

// #define MULTI_TESTCASE
#include "template/main.hpp"

void testcase() {
  auto n = input<int>();
  auto s = input<string>();

  vector cum(3, vector(n + 1, 0LL));
  rep (i, n) {
    cum[s[i] - 'A'][i + 1] = 1;
  }
  rep (k, 3)
    rep (i, n) cum[k][i + 1] += cum[k][i];

  auto f = [&](int l, int r) {
    lint res = LINF;
    rep (k, 3) chmin(res, cum[k][r] - cum[k][l]);
    return res;
  };

  lint ans = 0;
  int l = 0, r = 0;
  rep (i, n + 1) {
    if (f(0, i) < 2) continue;
    if (f(i, n) == 0) break;

    while (f(0, l) == 0) l++;
    while (f(r + 1, i) >= 1) r++;

    ans += max(r - l + 1, 0);
  }
  output(ans);
}
