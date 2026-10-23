#include "template/template.hpp"

// #define MULTI_TESTCASE
#include "template/main.hpp"

void testcase() {
  auto n = input<int>(), m = input<int>();
  auto a = input<vector<int>>(n), b = input<vector<int>>(m);

  rep (i, m) {
    auto it = ranges::find(a, b[i]);
    if (it != a.end()) a.erase(it);
  }
  output(a);
}
