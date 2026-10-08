#include "template/template.hpp"

#define MULTI_TESTCASE
#include "template/main.hpp"

void testcase() {
  auto n = input<int>();
  auto s = input<string>();

  int x = 0;
  for (char c: s) x ^= c - 'A' + 1;

  alicebob((s.size() % 2 == 0 && x != 0) || (s.size() % 2 == 1 && x == 0));
}
