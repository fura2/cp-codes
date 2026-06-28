// #define MULTI_TESTCASE
#include "template/template.hpp"

void testcase() {
  auto s = input<string>();
  int e = 0, w = 0;
  for (char c: s) {
    if (c == 'E') e++;
    if (c == 'W') w++;
  }
  if (e > w) {
    output("East");
  }
  else {
    output("West");
  }
}
