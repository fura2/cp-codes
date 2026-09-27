#include "template/template.hpp"

// #define MULTI_TESTCASE
#include "template/main.hpp"

void testcase() {
  auto n = input<int>(), k = input<int>();
  auto a = input<vector<int>>(n);

  int m = 1e6 + 1;
  vector<int> f(m), g(m);
  rep (i, n) f[a[i]]++;
  rep (d, 1, m) {
    for (int k = d; k < m; k += d) {
      g[d] += f[k];
    }
  }

  vector<int> h(m);
  rep (d, 1, m) {
    if (g[d] < k) continue;
    for (int k = d; k < m; k += d) {
      h[k] = d;
    }
  }
  rep (i, n) output(h[a[i]]);
}
