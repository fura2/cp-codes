#include "template/template.hpp"

// #define MULTI_TESTCASE
#include "template/main.hpp"

void testcase() {
  auto n = input<int>();
  string s;
  rep (_, n) {
    auto c = input<char>();
    auto l = input<lint>();
    if (l > 100) {
      output("Too Long");
      return;
    }
    s += string(l, c);
  }
  if (s.size() > 100) {
    output("Too Long");
  }
  else {
    output(s);
  }
}
