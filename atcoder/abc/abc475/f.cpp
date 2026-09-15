#include "template/template.hpp"

// #define MULTI_TESTCASE
#include "template/main.hpp"
#include "util/grid.hpp"

void testcase() {
  auto h = input<int>(), w = input<int>();
  auto G = input<Grid>(h, w);

  if (h > w) {
    G.transpose();
    swap(h, w);
  }

  vector cum(h + 1, vector(w + 1, 0));
  rep (i, h)
    rep (j, w)
      if (G[i][j] == '.') cum[i + 1][j + 1] = 1;
  rep (i, h + 1)
    rep (j, w) cum[i][j + 1] += cum[i][j];
  rep (j, w + 1)
    rep (i, h) cum[i + 1][j] += cum[i][j];

  auto rsum = [&](int t, int l, int b, int r) {
    return cum[b][r] - cum[t][r] - cum[b][l] + cum[t][l];
  };

  lint ans = 1;
  rep (t, h) {
    rep (b, t, h) {
      vector<int> js;
      rep (j, w)
        if (rsum(t, j, b + 1, j + 1) > 0) js.emplace_back(j);
      int m = js.size();
      int idx2 = 0;
      rep (idx1, m) {
        while (idx2 < m && (rsum(t, js[idx1], t + 1, js[idx2] + 1) == 0 ||
                            rsum(b, js[idx1], b + 1, js[idx2] + 1) == 0)) {
          idx2++;
        }
        if (idx2 == m) break;
        ans += m - idx2;
      }
    }
  }
  output(ans);
}
