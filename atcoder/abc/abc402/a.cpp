#include "template/template.hpp"

// #define MULTI_TESTCASE
#include "template/main.hpp"

void testcase() {
  auto s = input<string>();
  string t;
  for (char c: s)
    if (isupper(c)) t += c;
  output(t);
}
