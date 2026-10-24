#include "template/template.hpp"

// #define MULTI_TESTCASE
#include "template/main.hpp"

void testcase() {
  auto q = input<int>();
  map<string, int> f;
  rep (_, q) {
    auto s = input<string>();
    if (!f.contains(s)) {
      f[s] = f.size() + 1;
    }
    output(f[s]);
  }
}
