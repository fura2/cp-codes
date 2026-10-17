#include "template/template.hpp"

// #define MULTI_TESTCASE
#include "template/main.hpp"

void testcase() {
  auto n = input<int>();
  auto k = input<lint>(), t = input<lint>();
  auto a = input<vector<lint>>(n);

  a.emplace_back(t);

  ranges::sort(a);
  a.erase(ranges::unique(a).begin(), a.end());

  while (!a.empty() && a.back() > t) a.pop_back();

  lint ans = 0, x = 0;
  rep (i, a.size()) {
    if (x < a[i]) {
      ans += (a[i] - x + k - 1) / k;
    }
    x = a[i] + k;
  }
  output(ans);
}
