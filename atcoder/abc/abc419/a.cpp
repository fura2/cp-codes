#include "template/template.hpp"

// #define MULTI_TESTCASE
#include "template/main.hpp"

void testcase() {
  auto s = input<string>();
  if (s == "red")
    output("SSS");
  else if (s == "blue")
    output("FFF");
  else if (s == "green")
    output("MMM");
  else
    output("Unknown");
}
