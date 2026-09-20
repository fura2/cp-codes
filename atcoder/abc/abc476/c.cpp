#include "template/template.hpp"

// #define MULTI_TESTCASE
#include "template/main.hpp"

void testcase() {
  auto n = input<int>();
  auto a = input<vector<int>>(n);

  multiset<int, greater<>> S = {a[0], a[1]};
  rep (i, 2, n) {
    S.emplace(a[i]);
    output(*next(S.begin(), 2));
  }
}
