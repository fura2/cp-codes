#include "template/template.hpp"

// #define MULTI_TESTCASE

void testcase() {
  int x = input();
  int y = input();
  yesno(16 * y == 9 * x);
}

int main() {
#ifndef MULTI_TESTCASE
  testcase();
#else
  int t = input();
  rep (i, t) {
    std::clog << "\033[36mCase #" << i + 1 << "\033[0m" << std::endl;
    testcase();
  }
#endif
  return 0;
}
