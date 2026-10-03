#include "template/template.hpp"

// #define MULTI_TESTCASE
#include "template/main.hpp"

void testcase() {
  auto n = input<int>(), q = input<int>();
  vector<vector<int>> a(n + 1);
  rep (_, q) {
    auto l = input<int>() - 1, r = input<int>(), v = input<int>();
    a[l].emplace_back(v);
    a[r].emplace_back(-v);
  }

  vector<int> ans(n);
  map<int, int> cum;
  rep (i, n) {
    for (int v: a[i]) {
      if (v > 0)
        ++cum[v];
      else {
        v *= -1;
        if (--cum[v] == 0) {
          cum.erase(v);
        }
      }
    }
    ans[i] = cum.size();
  }
  output(ans);
}
