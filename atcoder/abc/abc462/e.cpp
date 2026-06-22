#include "template/template.hpp"

#define MULTI_TESTCASE

lint f(lint x, lint a, lint b) {
  return (x + 1) / 2 * min(a, 3 * b) + x / 2 * min(b, 3 * a);
}

void testcase() {
  lint a = input();
  lint b = input();
  lint tx = input();
  lint ty = input();
  tx = abs(tx);
  ty = abs(ty);

  lint tmin = min(tx, ty);
  lint ans = tmin * 2 * min(a, b);
  tx -= tmin;
  ty -= tmin;
  if (tx == 0) {
    swap(tx, ty);
    swap(a, b);
  }
  ans += f(tx, a, b);
  output(ans);
}

int main() {
#ifndef MULTI_TESTCASE
  testcase();
#else
  int t = input();
  rep (i, t) {
    // std::clog << "\033[32mCase #" << i + 1 << "\033[0m" << std::endl;
    testcase();
  }
#endif
  return 0;
}
