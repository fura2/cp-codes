#include "template/template.hpp"

// #define MULTI_TESTCASE
#include "template/main.hpp"

void testcase() {
  auto s = input<string>();
  int n = s.size();
  output(s.substr(0, n / 2) + s.substr(n / 2 + 1));
}
