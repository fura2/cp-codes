#include "template/template.hpp"

#define MULTI_TESTCASE
#include "template/main.hpp"
#include "util/isqrt.hpp"

lint f(lint c, lint b) {
  lint res = 0;
  lint ten = 1;
  rep (d, 11) {
    if (b >= ten) {
      res += isqrt(c * 10 * ten + min(b, 10 * ten - 1));
      res -= isqrt(c * 10 * ten + (ten - 1));
    }
    ten *= 10;
  }
  return res;
}

void testcase() {
  auto c = input<lint>(), d = input<lint>();
  output(f(c, c + d) - f(c, c - 1));
}
