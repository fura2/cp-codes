#include "template/template.hpp"

// #define MULTI_TESTCASE
#include "template/main.hpp"

void testcase() {
  auto n = input<int>(), m = input<int>();
  rep (i, n) {
    output(i < m ? "OK" : "Too Many Requests");
  }
}
