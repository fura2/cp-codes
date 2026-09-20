#include "template/template.hpp"

// #define MULTI_TESTCASE
#include "template/main.hpp"

void testcase() {
  auto n = input<int>(), m = input<int>();
  auto k = input<lint>();
  auto x = input<lint>(), y = input<lint>();
  auto a = input<vector<lint>>(n), b = input<vector<lint>>(m);

  ranges::sort(a);
  ranges::sort(b);

  vector<lint> acum(n + 1);
  rep (i, n) acum[i + 1] = acum[i] + a[i];

  int ans = 0;
  lint t = 0, r = 0;
  rep (j, m + 1) {
    lint z = x + (y - t) * k + r;
    int j2 = ranges::upper_bound(acum, z) - acum.begin() - 1;
    chmax(ans, j + j2);
    if (j < m) {
      t += (b[j] + k - 1) / k;
      r += (b[j] + k - 1) / k * k - b[j];
      if (t > y) break;
    }
  }
  output(ans);
}
