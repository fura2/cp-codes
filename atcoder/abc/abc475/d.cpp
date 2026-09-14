#include "template/template.hpp"

// #define MULTI_TESTCASE
#include "number_theory/eratosthenes_sieve.hpp"
#include "template/main.hpp"

void testcase() {
  auto s = input<string>();
  int n = s.size();

  for (auto p: EratosthenesSieve(1e7).primes()) {
    string t = to_string(p);
    if (t.size() != n) continue;
    bool ok = true;
    rep (i, n) {
      rep (j, i + 1, n) {
        if ((s[i] == s[j]) != (t[i] == t[j])) ok = false;
      }
    }
    if (ok) {
      output(p);
      return;
    }
  }
  output(-1);
}
