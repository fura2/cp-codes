// #define MULTI_TESTCASE
#include "template/template.hpp"

void testcase() {
  auto h = input<int>();
  auto w = input<int>();
  vector<string> B(h);
  rep (i, h) B[i] = input<string>();

  int t = h, l = w, b = 0, r = 0;
  rep (i, h)
    rep (j, w)
      if (B[i][j] == '#') {
        chmin(t, i);
        chmin(l, j);
        chmax(b, i);
        chmax(r, j);
      }

  rep (i, t, b + 1) {
    output(B[i].substr(l, r - l + 1));
  }
}
