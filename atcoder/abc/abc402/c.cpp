#include "template/template.hpp"

// #define MULTI_TESTCASE
#include "template/main.hpp"

void testcase() {
  auto n = input<int>(), m = input<int>();
  vector<vector<int>> a(m);
  rep (i, m) {
    auto k = input<int>();
    a[i].reserve(k);
    rep (j, k) a[i].emplace_back(input<int>() - 1);
  }
  auto b = input<vector<int>>(n, 1);

  vector<int> binv(n);
  rep (i, n) binv[b[i]] = i;

  vector<int> t(m);
  rep (i, m) {
    rep (j, a[i].size()) {
      chmax(t[i], binv[a[i][j]]);
    }
  }

  vector<int> ans(n);
  rep (i, m) ans[t[i]]++;
  rep (i, n - 1) ans[i + 1] += ans[i];
  output(ans);
}
