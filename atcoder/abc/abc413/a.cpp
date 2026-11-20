#include "template/template.hpp"

// #define MULTI_TESTCASE
#include "template/main.hpp"

void testcase() {
  auto n = input<int>(), m = input<int>();
  int sum = 0;
  rep (i, n) sum += input<int>();
  yesno(sum <= m);
}
