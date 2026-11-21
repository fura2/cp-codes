#include "template/template.hpp"

// #define MULTI_TESTCASE
#include "template/main.hpp"

void testcase() {
  auto n = input<int>(), k = input<int>();

  lint mx = 1;
  rep (i, k) mx *= 10;

  lint x = 1;
  rep (i, n) {
    auto a = input<lint>();
    if (a >= (mx + x - 1) / x)
      x = 1;
    else
      x *= a;
  }
  output(x);
}
