#include "template/template.hpp"

// #define MULTI_TESTCASE
#include "template/main.hpp"

void testcase() {
  auto n = input<int>(), m = input<int>();
  auto a = input<vector<int>>(n);
  while (set<int>(from_range, a).size() == m) {
    a.pop_back();
  }
  output(n - a.size());
}
