#include "template/template.hpp"

// #define MULTI_TESTCASE
#include "template/main.hpp"

void testcase() {
  auto h = input<int>(), w = input<int>(), n = input<int>();
  int t = h, l = w, b = 0, r = 0;
  rep (_, n) {
    int i = input<int>() - 1, j = input<int>() - 1;
    chmin(t, i);
    chmin(l, j);
    chmax(b, i);
    chmax(r, j);
  }
  alicebob(t ^ l ^ (h - b - 1) ^ (w - r - 1));
}
