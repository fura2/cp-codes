#include "template/template.hpp"

// #define MULTI_TESTCASE
#include "template/main.hpp"

void testcase() {
  auto n = input<int>();
  auto s = input<vector<string>>(n);
  auto x = input<int>() - 1;
  auto y = input<string>();
  yesno(s[x] == y);
}
