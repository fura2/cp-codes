#include "template/template.hpp"

#include <numeric>

// #define MULTI_TESTCASE
#include "template/main.hpp"

void testcase() {
  auto n = input<int>();
  vector<lint> a(n), b(n);
  rep (i, n) {
    a[i] = input<lint>();
    b[i] = input<lint>();
  }
  auto q = input<int>();
  auto qs = input<vector<int>>(q);

  const int m = 5e5 + 1;
  vector<vector<int>> Ev(m);
  rep (i, q) Ev[qs[i]].emplace_back(i);

  // (A_i, B_i) が等しいものをまとめる
  vector<lint> c;  // 重複度
  {
    map<pair<lint, lint>, int> H;
    rep (i, n) ++H[{a[i], b[i]}];
    a.clear();
    b.clear();
    for (auto [k, v]: H) {
      a.emplace_back(k.first);
      b.emplace_back(k.second);
      c.emplace_back(v);
    }
  }

  vector<lint> cum(m + 1);
  cum[0] = inner_product(a.begin(), a.end(), c.begin(), 0LL);
  rep (i, a.size()) {
    for (int x = b[i] - a[i]; x <= m; x += b[i]) {
      cum[x] -= c[i] * b[i];
    }
  }

  vector<lint> ans(q);
  rep (x, m) {
    for (int j: Ev[x]) ans[j] = cum[x];
    cum[x + 1] += cum[x] + n;
  }
  output(ans);
}
