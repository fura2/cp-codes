#include "template/template.hpp"

// #define MULTI_TESTCASE
#include "template/main.hpp"

void testcase() {
  auto k = input<int>();
  auto a = input<vector<int>>(k);
  output(ranges::contains(a, 9) ? ranges::min(a) : -1);
}
