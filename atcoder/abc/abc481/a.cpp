#include "template/template.hpp"

// #define MULTI_TESTCASE
#include "template/main.hpp"

void testcase() {
  auto a = input<int>(), b = input<int>();
  output(to_string(a + b).size());
}
