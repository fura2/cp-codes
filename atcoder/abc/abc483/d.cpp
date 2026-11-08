#include "template/template.hpp"

// #define MULTI_TESTCASE
#include "template/main.hpp"

void testcase() {
  auto n = input<int>();
  auto a = input<vector<lint>>(n);

  // (pos, left, right)
  vector<tuple<lint, lint, lint>> L(n + 1), R(n + 1);
  rep (i, n) {
    auto [c, l, r] = L[i];
    L[i + 1] = {c + a[i], min(c + a[i], l), max(c + a[i], r)};
  }
  rrep (i, n) {
    auto [c, l, r] = R[i + 1];
    R[i] = {c - a[i], min(c - a[i], l), max(c - a[i], r)};
  }
  // show(L);
  // show(R);

  lint ans = get<2>(L[n]) - get<1>(L[n]);
  rep (i, n) {
    lint l = min({get<1>(L[i]),
                  get<0>(L[i]) - a[i] + get<1>(R[i + 1]) - get<0>(R[i + 1])});
    lint r = max({get<2>(L[i]),
                  get<0>(L[i]) - a[i] + get<2>(R[i + 1]) - get<0>(R[i + 1])});
    chmax(ans, r - l);
    // show(i, l, r);
  }
  output(ans + 1);
}
