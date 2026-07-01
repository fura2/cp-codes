#include "template/template.hpp"

#define MULTI_TESTCASE
#include "template/main.hpp"

void testcase() {
  int h = input<int>();
  int w = input<int>();
  auto x = input<vector<int>>(h);
  auto y = input<vector<int>>(w);

  if (set(from_range, x).size() != x.size() ||
      set(from_range, y).size() != y.size()) {
    no();
    return;
  }

  vector<int> p(h * w + 1, -1), q(h * w + 1, -1);
  rep (i, h) p[x[i]] = i;
  rep (j, w) q[y[j]] = j;

  vector<int> R, C;          // free rows and columns
  vector<pair<int, int>> F;  // free cells
  vector ans(h, vector<int>(w, -1));
  rrep (v, 1, h * w + 1) {
    int i, j;
    if (p[v] != -1 && q[v] != -1) {
      i = p[v];
      j = q[v];
    }
    else if (p[v] != -1) {
      if (C.empty()) {
        no();
        return;
      }
      i = p[v];
      j = C[0];
    }
    else if (q[v] != -1) {
      if (R.empty()) {
        no();
        return;
      }
      i = R[0];
      j = q[v];
    }
    else {
      if (F.empty()) {
        no();
        return;
      }
      tie(i, j) = F.back();
      F.pop_back();
    }

    if (ans[i][j] != -1) {
      no();
      return;
    }
    ans[i][j] = v;

    if (p[v] != -1) {
      for (int c: C)
        if (ans[p[v]][c] == -1) F.emplace_back(p[v], c);
      R.emplace_back(p[v]);
    }
    if (q[v] != -1) {
      for (int r: R)
        if (ans[r][q[v]] == -1) F.emplace_back(r, q[v]);
      C.emplace_back(q[v]);
    }
  }

  yes();
  rep (i, h) output(ans[i]);
}
