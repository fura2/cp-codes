#include "template/template.hpp"

// #define MULTI_TESTCASE
#include "template/main.hpp"

void testcase() {
  auto n = input<int>(), m = input<int>();
  auto c = input<vector<lint>>(n);
  vector<vector<int>> A(n);
  rep (j, m) {
    auto k = input<int>();
    rep (_, k) {
      int i = input<int>() - 1;
      A[i].emplace_back(j);
    }
  }

  lint ans = LINF;
  rep (S, 1 << n) {
    for (int T = S;; T = (T - 1) & S) {
      lint cost = 0;
      vector<int> cnt(m);
      rep (i, n) {
        int k = 0;
        if (bit(S, i)) k++;
        if (bit(T, i)) k++;
        cost += k * c[i];
        for (int j: A[i]) cnt[j] += k;
      }

      bool ok = true;
      rep (j, m)
        if (cnt[j] < 2) ok = false;
      if (ok) chmin(ans, cost);

      if (T == 0) break;
    }
  }
  output(ans);
}
