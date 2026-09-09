#include "template/template.hpp"

// #define MULTI_TESTCASE
#include "template/main.hpp"

void testcase() {
  auto n = input<lint>();
  auto m = input<int>();
  vector<lint> a(m), b(m);
  rep (i, m) {
    a[i] = input<lint>();
    b[i] = input<lint>();
  }

  vector<int> p(m);
  ranges::iota(p, 0);
  ranges::sort(p, [&](int i, int j) { return a[i] - b[i] < a[j] - b[j]; });

  lint ans = 0;
  for (int i: p) {
    if (a[i] > n) continue;
    lint k = (n - a[i]) / (a[i] - b[i]) + 1;
    n -= k * (a[i] - b[i]);
    ans += k;
  }
  output(ans);
}
