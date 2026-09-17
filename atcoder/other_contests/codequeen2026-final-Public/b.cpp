#include "template/template.hpp"

// #define MULTI_TESTCASE
#include "template/main.hpp"

void testcase() {
  auto n = input<int>(), m = input<int>(), t = input<int>(), k = input<int>();
  map<int, int> f;
  rep (i, n + m) ++f[input<int>()];

  int ans = n + m, cons = 0;
  int t_pre = -1;
  for (auto [t, cnt]: f) {
    if (t > t_pre + 1) cons = 0;

    if (cnt < 2) {
      cons = 0;
    }
    else {
      if (cons == k) {
        ans--;
        cons = 0;
      }
      else {
        cons++;
      }
    }
    t_pre = t;
  }
  output(ans);
}
