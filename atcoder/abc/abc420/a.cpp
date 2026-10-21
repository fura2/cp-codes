#include "template/template.hpp"

// #define MULTI_TESTCASE
#include "template/main.hpp"

void testcase() {
  auto x = input<int>(), y = input<int>();
  output((x + y - 1) % 12 + 1);
}
