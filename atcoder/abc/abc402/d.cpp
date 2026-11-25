#include "template/template.hpp"

// #define MULTI_TESTCASE
#include "template/main.hpp"

void testcase() {
  auto n = input<int>(), m = input<int>();
  vector<int> a(m), b(m);
  rep (i, m) {
    a[i] = input<int>() - 1;
    b[i] = input<int>() - 1;
  }

  vector<int> cnt(n);
  rep (i, m) {
    cnt[(a[i] + b[i]) % n]++;
  }
  lint ans = m * (m - 1LL) / 2;
  for (int c: cnt) ans -= c * (c - 1LL) / 2;
  output(ans);
}
