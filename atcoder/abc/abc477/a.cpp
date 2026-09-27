#include "template/template.hpp"

// #define MULTI_TESTCASE
#include "template/main.hpp"

void testcase() {
  auto c = input<char>();
  output(c == 'B' ? 'Y' : c == 'Y' ? 'R' : 'B');
}
