#include "template/template.hpp"

// #define MULTI_TESTCASE
#include "number_theory/divisors.hpp"
#include "number_theory/linear_sieve.hpp"
#include "template/main.hpp"

void testcase() {
  auto lpf = LinearSieve(1e6).least_prime_factors();

  auto n = input<int>(), k = input<int>();
  auto a = input<vector<int>>(n);

  unordered_map<int, int> hist;
  rep (i, n) ++hist[a[i]];

  vector<int> dcnt(1e6 + 1);
  for (auto [e, c]: hist) {
    for (int d: divisors(e, lpf)) dcnt[d] += c;
  }

  unordered_map<int, int> res;
  for (auto [e, _]: hist) {
    int r = 1;
    for (int d: divisors(e, lpf)) {
      if (dcnt[d] >= k) chmax(r, d);
    }
    res[e] = r;
  }

  vector<int> ans(n);
  rep (i, n) ans[i] = res[a[i]];
  output(ans);
}
