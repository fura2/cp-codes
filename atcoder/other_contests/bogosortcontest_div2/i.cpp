#include "template/template.hpp"

#define MULTI_TESTCASE
#include "template/main.hpp"
#include "util/grid.hpp"

void testcase() {
  auto h = input<int>(), w = input<int>(), k = input<int>();
  auto B = input<Grid>(h, w);

  int sp = B.count('.');
  if (sp % 2 == 1) {
    output(sp);
    return;
  }

  vector cum(h + 1, vector(w + 1, 0));
  rep (i, h)
    rep (j, w)
      if (B[i][j] == '.') cum[i + 1][j + 1] = 1;
  rep (i, h + 1)
    rep (j, w) cum[i][j + 1] += cum[i][j];
  rep (j, w + 1)
    rep (i, h) cum[i + 1][j] += cum[i][j];

  int ans = 0;
  rep (i, h) {
    rep (j, w) {
      if (B[i][j] == '#') continue;
      int t = max(i - k, 0);
      int l = max(j - k, 0);
      int b = min(i + k + 1, h);
      int r = min(j + k + 1, w);
      if (cum[b][r] - cum[b][l] - cum[t][r] + cum[t][l] >= 3) ans++;
    }
  }
  output(ans);
}
