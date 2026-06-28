// #define MULTI_TESTCASE
#include "template/template.hpp"

void testcase() {
  auto h = input<int>();
  auto w = input<int>();
  auto q = input<int>();

  vector mx(h, vector(w, -1));
  string s;
  rep (i, q) {
    auto r = input<int>() - 1;
    auto c = input<int>() - 1;
    auto x = input<char>();
    chmax(mx[r][c], i);
    s += x;
  }
  rrep (i, 1, h)
    rrep (j, w) chmax(mx[i - 1][j], mx[i][j]);
  rrep (j, 1, w)
    rrep (i, h) chmax(mx[i][j - 1], mx[i][j]);

  vector B(h, string(w, 'A'));
  rep (i, h) {
    rep (j, w) {
      if (mx[i][j] != -1) B[i][j] = s[mx[i][j]];
    }
    cout << B[i] << "\n";
  }
}
