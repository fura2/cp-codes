#include "template/template.hpp"

// #define MULTI_TESTCASE
#include "template/main.hpp"

void testcase() {
  auto n = input<int>(), q = input<int>();
  vector<int> b(n);
  rep (_, q) {
    auto x = input<int>() - 1;
    if (x < 0) {
      x = min_element(b.begin(), b.end()) - b.begin();
    }
    output(x + 1);
    b[x]++;
  }
}
