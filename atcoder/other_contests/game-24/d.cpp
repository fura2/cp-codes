#include "template/template.hpp"

#define MULTI_TESTCASE
#include "template/main.hpp"

void testcase() {
  auto n = input<int>();
  vector<int> a(n), b(n);
  rep (i, n) {
    a[i] = input<int>();
    b[i] = input<int>();
  }

  bool win = false;
  rep (i, n)
    if (a[i] % (b[i] + 1) != 0) win = true;
  alicebob(win);
}
