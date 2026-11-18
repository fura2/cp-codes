#include "template/template.hpp"

// #define MULTI_TESTCASE
#include "template/main.hpp"

void testcase() {
  auto a = input<int>();
  output(200 <= a && a < 300 ? "Success" : "Failure");
}
