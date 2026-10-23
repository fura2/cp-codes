#include "template/template.hpp"

// #define MULTI_TESTCASE
#include "template/main.hpp"

void testcase() {
  auto n = input<int>(), a = input<int>(), b = input<int>();
  auto s = input<string>();
  output(s.substr(a, n - a - b));
}
