#include "template/template.hpp"

// #define MULTI_TESTCASE
#include "template/main.hpp"

void testcase() {
  auto n = input<int>(), m = input<int>();
  auto a = input<vector<int>>(n);
  int s = reduce(a.begin(), a.end());
  rep (i, n) {
    if (s - a[i] == m) {
      yes();
      return;
    }
  }
  no();
}
