#include "template/template.hpp"

// #define MULTI_TESTCASE
#include "template/main.hpp"

void testcase() {
  auto n = input<int>(), q = input<int>();
  auto a = input<vector<lint>>(n);

  vector<lint> cum(n + 1);
  rep (i, n) cum[i + 1] = cum[i] + a[i];

  int pos = 0;
  rep (_, q) {
    auto t = input<int>();
    if (t == 1) {
      auto c = input<int>();
      pos = (pos + c) % n;
    }
    else {
      auto l = input<int>() - 1, r = input<int>();
      if (l == 0 && r == n) {
        output(cum[n]);
        continue;
      }

      l = (l + pos) % n;
      r = (r + pos) % n;
      if (r == 0) r = n;

      lint ans;
      if (l <= r) {
        ans = cum[r] - cum[l];
      }
      else {
        ans = (cum[n] - cum[l]) + cum[r];
      }
      output(ans);
    }
  }
}
