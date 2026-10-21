#include "template/template.hpp"

// #define MULTI_TESTCASE
#include "template/main.hpp"

void testcase() {
  auto n = input<int>(), m = input<int>();
  auto s = input<vector<string>>(n);

  vector<int> res(n);
  rep (j, m) {
    int cnt[2] = {};
    rep (i, n) cnt[s[i][j] - '0']++;
    if (cnt[0] == cnt[1]) continue;
    rep (i, n)
      if (cnt[s[i][j] - '0'] == min(cnt[0], cnt[1])) res[i]++;
  }

  int mx = ranges::max(res);
  rep (i, n)
    if (res[i] == mx) output(i + 1);
}
