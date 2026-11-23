#include "template/template.hpp"

// #define MULTI_TESTCASE
#include "template/main.hpp"

void testcase() {
  auto n = input<int>(), k = input<int>(), x = input<int>() - 1;
  auto s = input<vector<string>>(n);

  vector<string> res;
  auto dfs = [&](auto&& dfs, string t, int i) {
    if (i == k) {
      res.emplace_back(t);
      return;
    }
    rep (j, n) dfs(dfs, t + s[j], i + 1);
  };
  dfs(dfs, "", 0);
  ranges::sort(res);
  output(res[x]);
}
