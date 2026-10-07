#include "template/template.hpp"

#include <cstdlib>

#define MULTI_TESTCASE
#include "template/main.hpp"

void testcase() {
  auto n = input<int>();
  vector<int> a(n), b(n);
  rep (i, n) {
    a[i] = input<int>();
    b[i] = input<int>();
  }

  bool win = true, lose = true;
  rep (i, n) {
    if (a[i] % (b[i] + 1) == 0) {
      win = false;
    }
    else {
      lose = false;
    }
  }
  if (win) {
    alice();
    return;
  }
  if (lose) {
    bob();
    return;
  }

  int winmin = 2e9, losemin = 2e9;
  rep (i, n) {
    if (a[i] % (b[i] + 1) == 0) {
      chmin(losemin, a[i] / (b[i] + 1) * 2);
    }
    else {
      chmin(winmin, 1 + a[i] / (b[i] + 1) * 2);
    }
  }
  alicebob(winmin < losemin);
}
