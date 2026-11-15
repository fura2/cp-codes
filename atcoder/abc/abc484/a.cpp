#include "template/template.hpp"

// #define MULTI_TESTCASE
#include "template/main.hpp"

void testcase() {
  auto b = input<int>(), r = input<int>();
  output((30 - b) * (30 - r));
}
