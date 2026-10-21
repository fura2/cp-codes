#include "template/template.hpp"

// #define MULTI_TESTCASE
#include "template/main.hpp"

void testcase() {
  auto n = input<int>(), q = input<int>();
  auto a = input<vector<lint>>(n), b = input<vector<lint>>(n);

  lint ans = 0;
  rep (i, n) ans += min(a[i], b[i]);

  rep (_, q) {
    auto t = input<char>();
    auto i = input<int>() - 1;
    auto v = input<lint>();
    ans -= min(a[i], b[i]);
    (t == 'A' ? a : b)[i] = v;
    ans += min(a[i], b[i]);
    output(ans);
  }
}
