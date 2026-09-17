#include "template/template.hpp"

// #define MULTI_TESTCASE
#include "template/main.hpp"

void testcase() {
  auto n = input<int>();
  auto a = input<vector<int>>(n, 1);

  vector<bool> b(n);
  rep (i, n) {
    if (a[i] >= 0) {
      if (b[a[i]]) {
        no();
        return;
      }
      b[a[i]] = true;
    }
  }
  rep (i, n) {
    if (a[i] < 0) {
      for (int x = 0;; x++) {
        if (!b[x]) {
          b[x] = true;
          a[i] = x;
          break;
        }
      }
    }
  }
  yes();
  output(a, 1);
}
