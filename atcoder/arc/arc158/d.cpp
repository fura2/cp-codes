#include "template/template.hpp"

#define MULTI_TESTCASE
#include "number_theory/modpow.hpp"
#include "template/main.hpp"

void testcase() {
  auto n = input<lint>(), p = input<lint>();

  mt19937 rng;
  while (true) {
    lint x = rng() % (p - 1) + 1;
    lint y = rng() % (p - 1) + 1;
    lint z = rng() % (p - 1) + 1;
    lint s = (x + y + z) % p;
    if (x == y || x == z || y == z || s == 0) continue;

    lint x1 = modpow(x, n, p);
    lint y1 = modpow(y, n, p);
    lint z1 = modpow(z, n, p);
    lint s1 = (x1 + y1 + z1) % p;
    if (s1 == 0) continue;

    lint x2 = x1 * x1 % p;
    lint y2 = y1 * y1 % p;
    lint z2 = z1 * z1 % p;
    lint s2 = (x2 + y2 + z2) % p;
    if (s2 == 0) continue;

    lint x3 = x1 * x2 % p;
    lint y3 = y1 * y2 % p;
    lint z3 = z1 * z2 % p;
    lint s3 = (x3 + y3 + z3) % p;
    if (s3 == 0) continue;

    lint t = modpow(s * s1 % p * s2 % p, p - 2, p) * s3 % p;
    vector<lint> ans = {t * x % p, t * y % p, t * z % p};
    ranges::sort(ans);
    output(ans);
    break;
  }
}
