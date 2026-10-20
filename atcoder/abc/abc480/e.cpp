#include "template/template.hpp"

// #define MULTI_TESTCASE
#include "template/main.hpp"

lint f(lint n, lint l, lint a) {
  lint lo = 0, hi = 1e9;
  while (hi - lo > 1) {
    lint mi = (lo + hi) / 2;
    bool ok = true;
    lint x = 1;
    rep (i, l) {
      if (x > n / (a + i * mi)) {
        ok = false;
        break;
      }
      x *= a + i * mi;
    }
    (ok ? lo : hi) = mi;
  }
  return lo;
}

void testcase() {
  auto n = input<lint>();
  lint ans = 0;
  rep (l, 3, 30) {
    for (lint a = 1;; a++) {
      bool ok = true;
      lint x = 1;
      rep (i, l) {
        if (x > n / a) {
          ok = false;
          break;
        }
        x *= a;
      }
      if (!ok) break;
      // a^l <= n
      ans += f(n, l, a);
    }
  }
  output(ans);
}
