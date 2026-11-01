#include "template/template.hpp"

// #define MULTI_TESTCASE
#include "template/main.hpp"

void testcase() {
  auto s = input<string>();
  output(ranges::count(s, 'o') % 2 == 1 ? "odd" : "even");
}
