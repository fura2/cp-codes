#include "template/template.hpp"

// #define MULTI_TESTCASE
#include "template/main.hpp"

void testcase() {
  auto n = input<int>(), q = input<int>();
  auto a = input<vector<lint>>(n);

  lint mx = ranges::max(a);

  int m = 1e6 + 1;
  vector<lint> cum(m);
  cum[0] = n;
  rep (i, n) cum[a[i] + 1]--;
  rep (x, m - 1) cum[x + 1] += cum[x];

  vector<lint> res(m);
  rep (x, 1, m) {
    res[x] = res[x - 1] + cum[x];
  }

  rep (_, q) {
    auto b = input<lint>();
    if (b > mx) {
      output(-1);
    }
    else {
      output(res[b - 1] + 1);
    }
  }
}
