#include "template/template.hpp"

// #define MULTI_TESTCASE
#include "template/main.hpp"

void testcase() {
  auto n = input<int>(), m = input<int>();
  vector<int> cum(n + 1);
  rep (i, m) {
    auto l = input<int>() - 1, r = input<int>();
    cum[l]++;
    cum[r]--;
  }
  rep (i, n) cum[i + 1] += cum[i];
  output(*min_element(cum.begin(), cum.end() - 1));
}
