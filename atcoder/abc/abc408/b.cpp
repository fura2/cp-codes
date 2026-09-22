#include "template/template.hpp"

// #define MULTI_TESTCASE
#include "template/main.hpp"

void testcase() {
  auto n = input<int>();
  auto a = input<vector<int>>(n);
  a = vector(from_range, set(from_range, a));
  output(a.size());
  output(a);
}
