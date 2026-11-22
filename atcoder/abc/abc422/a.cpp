#include "template/template.hpp"

// #define MULTI_TESTCASE
#include "template/main.hpp"

void testcase() {
  auto a = input<int>();
  auto c = input<char>();
  auto b = input<int>();
  if (b == 8)
    a++, b = 1;
  else
    b++;
  output(format("{}{}{}", a, c, b));
}
