#include "template/template.hpp"

// #define MULTI_TESTCASE
#include "template/main.hpp"

void testcase() {
  auto s = input<string>();
  if (s.back() == 'e')
    s += "r";
  else
    s += "er";
  output(s);
}
