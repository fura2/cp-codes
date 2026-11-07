#include "template/template.hpp"

// #define MULTI_TESTCASE
#include "template/main.hpp"

void testcase() {
  auto s = input<string>();
  map<char, int> h;
  for (char c: s) ++h[c];
  for (auto [c, v]: h)
    if (v == 1) output(c);
}
