#include "template/template.hpp"

// #define MULTI_TESTCASE

void testcase() {
  string s = input();
  for (char c: s) {
    if (isdigit(c)) cout << c;
  };
}

int main() {
#ifndef MULTI_TESTCASE
  testcase();
#else
  int t = input();
  rep (i, t) {
    std::clog << "\033[32mCase #" << i + 1 << "\033[0m" << std::endl;
    testcase();
  }
#endif
  return 0;
}
