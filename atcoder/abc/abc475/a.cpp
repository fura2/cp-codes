#include "template/template.hpp"

// #define MULTI_TESTCASE
#include "template/main.hpp"

void testcase() {
  auto s = input<string>();
  int n = s.size();
  string t;
  rep (i, n) {
    if (i > 0) t += "o";
    t += s[i];
  }
  output(t);
}
