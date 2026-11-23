#include "template/template.hpp"

// #define MULTI_TESTCASE
#include "template/main.hpp"

void testcase() {
  auto s = input<string>();
  int n = s.size();

  bool b = false;
  rep (i, n) {
    if (s[i] == '.') {
      if (!b) {
        s[i] = 'o';
        b = true;
      }
    }
    else {
      b = false;
    }
  }
  output(s);
}
