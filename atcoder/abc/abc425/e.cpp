#include "template/template.hpp"

// #define MULTI_TESTCASE
#include "number_theory/linear_sieve.hpp"
#include "number_theory/modinv.hpp"
#include "number_theory/modpow.hpp"
#include "template/main.hpp"

void testcase() {
  LinearSieve S(5000);

  auto t = input<int>(), m = input<int>();

  // pf[x] = (x! の素因数分解の M の素因数への制限)
  vector<map<int, int>> pf(5001);
  rep (x, 2, 5001) {
    pf[x] = pf[x - 1];
    for (auto [p, e]: S.prime_factorization(x)) {
      if (m % p == 0) pf[x][p] += e;
    }
  }

  // r[x] = (x! の M の素因数を除いた部分) mod M
  vector<lint> r(5001);
  r[1] = 1;
  rep (x, 2, 5001) {
    int y = x;
    while (true) {
      int g = gcd(y, m);
      if (g == 1) break;
      y /= g;
    }
    r[x] = r[x - 1] * y % m;
  }

  rep (_, t) {
    auto n = input<int>();
    auto a = input<vector<int>>(n);

    int asum = accumulate(a.begin(), a.end(), 0);
    map<int, int> qf = pf[asum];
    rep (i, n) {
      for (auto [p, e]: pf[a[i]]) qf[p] -= e;
    }

    lint ans = r[asum];
    rep (i, n) {
      ans = ans * modinv(r[a[i]], m) % m;
    }
    for (auto [p, e]: qf) {
      ans = ans * modpow(p, e, m) % m;
    }
    output(ans);
  }
}
