#include "template/template.hpp"

// #define MULTI_TESTCASE
#include "template/main.hpp"

void testcase() {
  auto n = input<int>(), l = input<int>() - 1, r = input<int>();
  auto s = input<string>();
  bool ok = true;
  rep (i, l, r)
    if (s[i] != 'o') ok = false;
  yesno(ok);
}
