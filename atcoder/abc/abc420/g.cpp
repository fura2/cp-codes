#include "template/template.hpp"

// #define MULTI_TESTCASE
#include "template/main.hpp"

void testcase() {
  auto x = input<lint>();

  vector<lint> D;
  for (lint d = 1, y = abs(4 * x - 1); d * d <= y; ++d) {
    if (y % d == 0) {
      D.emplace_back(d);
      D.emplace_back(-d);
      if (d * d < y) {
        D.emplace_back(y / d);
        D.emplace_back(-y / d);
      }
    }
  }

  vector<lint> ans;
  for (lint d: D) {
    lint s = (4 * x - 1) / d;
    if ((s + d) % 4 != 0) continue;
    if ((s - d - 2) % 4 != 0) continue;
    lint m = (s + d) / 4;
    lint n = (s - d - 2) / 4;
    if (m >= 0) {
      ans.emplace_back(n);
    }
  }
  ranges::sort(ans);
  output(ans.size());
  output(ans);
}
