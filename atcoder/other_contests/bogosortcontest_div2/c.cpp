#include "template/template.hpp"

#define MULTI_TESTCASE
#include "template/main.hpp"

void testcase() {
  auto s = input<string>();
  int k = input<int>();
  int n = s.size();

  vector<int> a(n - 2);
  rep (i, n - 2) {
    if (s[i] == s[i + 2]) a[i] = 1;
  }
  vector<int> cum(n - 1);
  rep (i, n - 2) cum[i + 1] = cum[i] + a[i];

  lint ans = 0;
  rep (i, n - 2) {
    if (a[i] != 1) continue;
    ans += cum[min(i + k - 2, n - 2)] - cum[i];
  }
  output(ans);
}
