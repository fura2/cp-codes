#include "template/template.hpp"

// #define MULTI_TESTCASE
#include "template/main.hpp"

void testcase() {
  auto n = input<int>();
  auto s = input<string>(), t = input<string>();
  rep (i, n) {
    if (s[i] == 'o' && t[i] == 'o') {
      yes();
      return;
    }
  }
  no();
}
