#include "template/template.hpp"

// #define MULTI_TESTCASE
#include "template/main.hpp"

void testcase() {
  auto n = input<int>();
  auto a = input<vector<int>>(n);

  rrep (i, n - 1) a[i + 1] -= a[i];
  int x = 0;
  for (int i = n - 1; i >= 0; i -= 2) x ^= a[i];
  output(x != 0 ? "First" : "Second");
}
