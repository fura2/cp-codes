#include "template/template.hpp"

// #define MULTI_TESTCASE
#include "template/main.hpp"

void testcase() {
  auto n = input<int>();
  auto m = input<lint>();
  auto c = input<int>();
  auto a = input<vector<lint>>(n);

  vector<lint> C = {0, m};
  rep (i, n) {
    C.emplace_back(a[i]);
    C.emplace_back(m + a[i]);
  }
  uniq(C);
  int k = C.size();

  vector<int> h(k);
  rep (i, n) {
    int x = ranges::lower_bound(C, a[i]) - C.begin();
    ++h[x];
    x = ranges::lower_bound(C, m + a[i]) - C.begin();
    ++h[x];
  }
  vector<int> cum(k + 1);
  rep (i, k) cum[i + 1] = cum[i] + h[i];

  lint ans = 0;
  rep (i, k) {
    if (C[i] >= m) break;
    int pos = lower_bound(cum.begin() + i + 1, cum.end(), c + cum[i + 1]) -
              cum.begin();
    ans += (cum[pos] - cum[i + 1]) * (C[i + 1] - C[i]);
  }
  output(ans);
}
