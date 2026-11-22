#include "template/template.hpp"

#define MULTI_TESTCASE
#include "template/main.hpp"

bool f(lint a, lint b, lint c, lint x) {
  if (a < x) return false;
  if (c < x) return false;
  a -= x;
  c -= x;
  return a + b + c >= x;
}

void testcase() {
  auto a = input<lint>(), b = input<lint>(), c = input<lint>();
  lint lo = 0, hi = 1e9 + 1;
  while (hi - lo > 1) {
    lint mi = (lo + hi) / 2;
    (f(a, b, c, mi) ? lo : hi) = mi;
  }
  output(lo);
}
