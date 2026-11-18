#include "template/template.hpp"

// #define MULTI_TESTCASE
#include "template/main.hpp"

void testcase() {
  auto n = input<int>(), k = input<int>();

  if (n < k) {
    output(1);
    return;
  }

  int mod = 1000000000;
  vector<int> a(n + 1);
  rep (i, k) a[i] = 1;
  int cum = k;
  rep (i, k, n + 1) {
    a[i] = cum;
    cum = (cum + a[i] - a[i - k]) % mod;
    if (cum < 0) cum += mod;
  }
  output(a[n]);
}
