#include "template/template.hpp"

#define MULTI_TESTCASE
#include "template/main.hpp"

void testcase() {
  auto n = input<int>();
  vector<int> a(n);
  rep (i, n) {
    rep (j, n) a[j] = gcd(i + 1, j + 1);
    output(a);
  }
}
