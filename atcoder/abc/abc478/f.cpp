#include "template/template.hpp"

// #define MULTI_TESTCASE
#include "mint/mint.hpp"
#include "template/main.hpp"

void testcase() {
  auto n = input<int>();
  auto p = input<vector<int>>(n, 1);

  mint ans = 1;
  rep (i, 1, n) {
    int j = i - 1;
    while (j > 0 && p[j] < p[i]) j--;
    ans *= i - j;
  }
  output(ans);
}
