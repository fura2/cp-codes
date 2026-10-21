#include "template/template.hpp"

// #define MULTI_TESTCASE
#include "template/main.hpp"

void testcase() {
  auto n = input<int>();
  auto a = input<vector<int>>(n, 1);

  vector<lint> H(n);
  rep (i, n) ++H[a[i]];

  lint ans = 0;
  rep (x, n) {
    ans += H[x] * (H[x] - 1) * (n - H[x]) / 2;
  }
  output(ans);
}
