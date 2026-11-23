#include "template/template.hpp"

#define MULTI_TESTCASE
#include "template/main.hpp"

void testcase() {
  auto n = input<int>();
  auto m = input<lint>();
  auto a = input<vector<lint>>(n), b = input<vector<lint>>(n);

  ranges::sort(a);
  ranges::sort(b, greater{});

  int pos = 0;
  rep (i, n) {
    if (pos < n && a[i] + b[pos] >= m) pos++;
  }
  output(ranges::fold_left(a, 0LL, plus{}) + ranges::fold_left(b, 0LL, plus{}) -
         m * pos);
}
