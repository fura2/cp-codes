#include "template/template.hpp"

// #define MULTI_TESTCASE
#include "template/main.hpp"

void testcase() {
  auto n = input<int>();
  auto s = input<string>();
  yesno(s.size() >= 3 && s.substr(n - 3) == "tea");
}
