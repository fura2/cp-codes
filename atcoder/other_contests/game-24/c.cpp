#include "template/template.hpp"

#define MULTI_TESTCASE
#include "template/main.hpp"

void testcase() {
  auto a = input<lint>(), b = input<lint>(), c = input<lint>(),
       d = input<lint>();

  lint x = 2 * b, y = 2 * a;
  lint k = min(c, d);
  c -= k;
  d -= k;
  if (c == 0) {
    x += d / 2;
    if (d % 2 == 1) {
      if (y == 0) {
        alice();
        return;
      }
      y--;
    }
  }
  else {  // d == 0
    y += c / 2;
  }
  alicebob(x > y);
}
