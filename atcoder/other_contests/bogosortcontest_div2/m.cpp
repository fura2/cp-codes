#include "template/template.hpp"

// #define MULTI_TESTCASE
#include "template/main.hpp"

void testcase() {
  auto n = input<int>();
  auto r = input<vector<int>>(n - 1);
  auto w = input<vector<int>>(n - 1);

  vector<multiset<int>> W(n - 1);
  rep (i, n - 1) {
    W[i].emplace(1e9);
    rep (j, r[i]) W[i + j].emplace(w[i]);
  }
  lint ans = 0;
  rep (i, n - 1) {
    ans += *W[i].begin();
  }

  auto q = input<int>();
  rep (_, q) {
    auto i2 = input<int>() - 1, r2 = input<int>(), w2 = input<int>();
    rep (j, r[i2]) {
      ans -= *W[i2 + j].begin();
      W[i2 + j].erase(W[i2 + j].find(w[i2]));
      ans += *W[i2 + j].begin();
    }
    r[i2] = r2;
    w[i2] = w2;
    rep (j, r[i2]) {
      ans -= *W[i2 + j].begin();
      W[i2 + j].emplace(w[i2]);
      ans += *W[i2 + j].begin();
    }
    output(ans);
  }
}
