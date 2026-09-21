#include "template/template.hpp"

// #define MULTI_TESTCASE
#include "number_theory/eratosthenes_sieve.hpp"
#include "number_theory/segmented_sieve.hpp"
#include "template/main.hpp"

void testcase() {
  auto l = input<lint>(), r = input<lint>();

  if (l == r) {
    output(1);
    return;
  }

  auto ps = EratosthenesSieve(1e7).primes();
  SegmentedSieve S(l + 1, r, ps);

  int ans = 1 + S.primes().size();
  for (lint p: ps) {
    lint q = p * p;
    while (true) {
      if (l < q && q <= r) ans++;
      if (q > r / p) break;
      q *= p;
    }
  }
  output(ans);
}
