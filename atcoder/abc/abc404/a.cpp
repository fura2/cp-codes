#include "template/template.hpp"

// #define MULTI_TESTCASE
#include "template/main.hpp"

void testcase() {
  auto s = input<string>();
  for (char c = 'a';; c++) {
    if (ranges::count(s, c) == 0) {
      output(c);
      return;
    }
  }
}
