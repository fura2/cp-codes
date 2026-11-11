#include "template/template.hpp"

// #define MULTI_TESTCASE
#include "template/main.hpp"

void testcase() {
  auto a = input<int>(), b = input<int>();
  int c = a / b;
  if (abs(c - 1.0 * a / b) > abs(c + 1 - 1.0 * a / b)) c++;
  output(c);
}
