#include "template/template.hpp"

// #define MULTI_TESTCASE
#include "template/main.hpp"

void testcase() {
  int n = input<int>();
  auto a = input<vector<lint>>(n);

  lint sum = 0, sqsum = 0;
  rep (i, n) {
    sum += a[i];
    sqsum += a[i] * a[i];
  }
  output((sum * sum - sqsum) / 2);
}
