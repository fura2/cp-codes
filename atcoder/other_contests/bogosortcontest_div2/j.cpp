#include "template/template.hpp"

// #define MULTI_TESTCASE
#include "template/main.hpp"

void testcase() {
  auto n = input<int>(), t = input<int>();
  vector<int> l(n), r(n);
  rep (i, n) {
    l[i] = input<int>();
    r[i] = input<int>();
  }

  double lo = 0, hi = 1e15;
  vector memo(1 << n, vector<double>(t + 1, -1.0));
  rep (_, 100) {
    rep (S, 1 << n)
      rep (j, t + 1) memo[S][j] = -1;

    double mi = (lo + hi) / 2;
    auto f = [&](auto&& f, int S, int x) -> double {
      if (x > t) return mi;

      if (memo[S][x] != -1) return memo[S][x];

      if (S == (1 << n) - 1) {
        return memo[S][x] = 0.0;
      }
      double y = mi;
      rep (i, n) {
        if (bit(S, i) == 1) continue;
        double tmp = 0;
        rep (j, l[i], r[i] + 1) {
          tmp += j + f(f, S | (1 << i), x + j);
        }
        chmin(y, tmp / (r[i] - l[i] + 1));
      }
      return memo[S][x] = y;
    };
    double tmp = f(f, 0, 0);
    (tmp < mi ? hi : lo) = mi;
  }
  output(lo);
}
