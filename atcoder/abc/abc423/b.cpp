#include "template/template.hpp"

// #define MULTI_TESTCASE
#include "template/main.hpp"

void testcase() {
  auto n = input<int>();
  auto a = input<vector<int>>(n);

  int ans = 0;
  rep (i, n + 1) {
    if (ranges::contains(a.begin(), a.begin() + i, 1) &&
        ranges::contains(a.begin() + i, a.end(), 1))
      ans++;
  }
  output(ans);
}
