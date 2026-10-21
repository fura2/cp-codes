#include "template/template.hpp"

// #define MULTI_TESTCASE
#include "template/main.hpp"
#include "util/compression.hpp"

void testcase() {
  auto n = input<int>();
  auto m = input<lint>();
  auto c = input<int>();
  auto a = input<vector<lint>>(n);

  Compression<lint> C;
  a.emplace_back(0);
  for (lint x: a) {
    C.add(x);
    C.add(m + x);
  }
  C.build();

  int k = C.size();
  vector<int> h(k);
  rep (i, n) {
    ++h[C.index(a[i])];
    ++h[C.index(m + a[i])];
  }
  vector<int> cum(k + 1);
  rep (i, k) cum[i + 1] = cum[i] + h[i];

  lint ans = 0;
  rep (i, k) {
    if (C.value(i) >= m) break;
    int pos = lower_bound(cum.begin() + i + 1, cum.end(), c + cum[i + 1]) -
              cum.begin();
    ans += (cum[pos] - cum[i + 1]) * (C.value(i + 1) - C.value(i));
  }
  output(ans);
}
