#include "template/template.hpp"

// #define MULTI_TESTCASE
#include "template/main.hpp"

void testcase() {
  auto n = input<int>(), l = input<int>();
  map<int, lint> h;
  int x = 0;
  ++h[x];
  rep (_, n - 1) {
    x += input<int>();
    x %= l;
    ++h[x];
  }

  if (l % 3 != 0) {
    output(0);
    return;
  }

  lint ans = 0;
  for (auto [x, v]: h) {
    int y = (x + l / 3) % l;
    int z = (y + l / 3) % l;
    ans += v * h[y] * h[z];
  }
  ans /= 3;
  output(ans);
}
