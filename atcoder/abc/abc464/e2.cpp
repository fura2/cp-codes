// #define MULTI_TESTCASE
#include "template/template.hpp"

void testcase() {
  auto h = input<int>();
  auto w = input<int>();
  auto q = input<int>();
  vector<int> r(q), c(q);
  vector<char> x(q);
  rep (i, q) {
    r[i] = input<int>();
    c[i] = input<int>();
    x[i] = input<char>();
  }

  vector P(h, vector(w, -1));
  rrep (k, q) {
    rrep (i, r[k]) {
      if (P[i][c[k] - 1] != -1) break;
      rrep (j, c[k]) {
        if (P[i][j] != -1) break;
        P[i][j] = k;
      }
    }
  }

  rep (i, h) {
    string s(w, '?');
    rep (j, w) s[j] = (P[i][j] == -1 ? 'A' : x[P[i][j]]);
    output(s);
  }
}
