#include "template/template.hpp"

// #define MULTI_TESTCASE
#include "mint/mint.hpp"
#include "number_theory/eratosthenes_sieve.hpp"
#include "template/main.hpp"

void testcase() {
  EratosthenesSieve S(1e6);
  auto ps = S.primes();

  auto n = input<lint>(), k = input<lint>();

  unordered_map<lint, int> pf;
  rep (t, 2) {
    lint l, r;
    if (t == 0)
      l = n - k + 1, r = n;
    else
      l = 1, r = k;

    vector<lint> rem(r - l + 1);
    rep (i, r - l + 1) rem[i] = l + i;
    for (lint p: ps) {
      if (p * p > r) break;
      for (lint x = (l + p - 1) / p * p; x <= r; x += p) {
        int e = 0;
        do {
          e++;
          rem[x - l] /= p;
        } while (rem[x - l] % p == 0);
        pf[p] += (t == 0 ? e : -e);
      }
    }
    rep (i, r - l + 1)
      if (rem[i] > 1) pf[rem[i]] += (t == 0 ? 1 : -1);
  }

  mint ans = 1;
  for (auto [p, e]: pf) ans *= e + 1;
  output(ans);
}
