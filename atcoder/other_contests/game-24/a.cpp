#include "template/template.hpp"

// #define MULTI_TESTCASE
#include "template/main.hpp"

void testcase() {
  auto n = input<int>();
  auto a = input<vector<int>>(n);
  alicebob(ranges::fold_left(a, 0, bit_xor{}) != 0);
}
