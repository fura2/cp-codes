#include "template/template.hpp"

// #define MULTI_TESTCASE
#include "template/main.hpp"

void testcase() {
  auto s = input<string>();
  auto l = input<int>();
  yesno(s.size() >= l);
}
