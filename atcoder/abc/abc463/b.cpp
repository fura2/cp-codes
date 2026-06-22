#include "template/template.hpp"

// #define MULTI_TESTCASE

void testcase() {
  int n = input();
  char c = input();
  rep (i, n) {
    string s = input();
    if (s[c - 'A'] == 'o') {
      yes();
      return;
    }
  }
  no();
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
