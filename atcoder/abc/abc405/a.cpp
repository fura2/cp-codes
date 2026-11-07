#include "template/template.hpp"

// #define MULTI_TESTCASE
#include "template/main.hpp"

void testcase() {
  auto r = input<int>(), x = input<int>();
  if (x == 1) {
    yesno(1600 <= r && r < 3000);
  }
  else {
    yesno(1200 <= r && r < 2400);
  }
}
