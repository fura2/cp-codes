#include "template/template.hpp"

// #define MULTI_TESTCASE
#include "template/main.hpp"

void testcase() {
  auto n = input<int>(), m = input<int>(), k = input<int>();
  vector<int> cnt(n);
  rep (_, k) {
    auto a = input<int>() - 1, b = input<int>() - 1;
    cnt[a]++;
    if (cnt[a] == m) {
      output(a + 1);
    }
  }
}
