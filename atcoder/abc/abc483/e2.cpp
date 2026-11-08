#include "template/template.hpp"

// #define MULTI_TESTCASE
#include "set_operation/moebius_transform.hpp"
#include "template/main.hpp"

void testcase() {
  auto n = input<int>(), m = input<int>();
  auto s = input<vector<string>>(n);

  vector<lint> g(1 << m);
  rep (S, 1 << m) {
    if (popcount(uint(S)) > 2) continue;

    unordered_map<string, int> h;
    rep (i, n) {
      auto t = s[i];
      rep (j, m)
        if (bit(S, j) == 1) t[j] = '?';
      g[S] += h[t]++;
    }
  }

  auto f = subset_moebius_transform(g);

  lint ans = 0;
  rep (S, 1 << m)
    if (popcount(uint(S)) <= 2) ans += f[S];
  output(ans);
}
