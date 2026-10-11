#include "template/template.hpp"

#define MULTI_TESTCASE
#include "template/main.hpp"

void testcase() {
  auto n = input<int>();
  auto a = input<vector<lint>>(n);

  if (a[0] != ranges::min(a)) {
    output(-1);
    return;
  }

  lint ans = 0;
  rrep (i, n - 1) {
    if (a[i] > a[i + 1]) {
      ans += a[i] - a[i + 1];
      a[i] = a[i + 1];
    }
  }
  output(ans);
}
