#include "template/template.hpp"

// #define MULTI_TESTCASE
#include "template/main.hpp"

void testcase() {
  auto n = input<int>(), d = input<int>();
  auto x = input<vector<int>>(n);

  vector<int> ans;
  rep (i, n) {
    bool ok = true;
    rep (j, n)
      if (j != i && abs(x[i] - x[j]) < d) ok = false;
    if (ok) ans.emplace_back(i);
  }
  output(ans.size());
  output(ans, 1);
}
