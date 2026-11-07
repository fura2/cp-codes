#include "template/template.hpp"

// #define MULTI_TESTCASE
#include "template/main.hpp"

void testcase() {
  auto n = input<int>(), q = input<int>();

  map<int, int> f;
  rep (i, n) ++f[i + 1] = 1;

  rep (_, q) {
    int x = input<int>(), y = input<int>();
    int ans = 0;
    while (f.begin()->first <= x) {
      f[y] += f.begin()->second;
      ans += f.begin()->second;
      f.erase(f.begin());
    }
    output(ans);
  }
}
