#include "template/template.hpp"

// #define MULTI_TESTCASE
#include "template/main.hpp"

void testcase() {
  auto n = input<int>();
  auto a = input<vector<int>>(n);

  int r = 1;
  vector<int> ans(n);
  while (true) {
    int mx = ranges::max(a);
    if (mx == -1) break;
    vector<int> p;
    rep (i, n)
      if (a[i] == mx) p.emplace_back(i);
    for (int i: p) ans[i] = r, a[i] = -1;
    r += p.size();
  }
  output(ans);
}
