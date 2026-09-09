#include "template/template.hpp"

// #define MULTI_TESTCASE
#include "template/main.hpp"

void testcase() {
  auto n = input<int>(), m = input<int>();
  vector<int> l(m), r(m);
  rep (i, m) {
    l[i] = input<int>() - 1;
    r[i] = input<int>();
  }

  map<pair<int, int>, int> H;  // histogram
  rep (i, m) ++H[{l[i], r[i]}];
  vector<vector<int>> l2rs(n + 1), r2ls(n + 1);
  rep (i, m) {
    l2rs[l[i]].emplace_back(r[i]);
    r2ls[r[i]].emplace_back(l[i]);
  }
  rep (x, n + 1) {
    ranges::sort(l2rs[x]);
    ranges::sort(r2ls[x]);
  }

  // rmin[x] = (左端が x 以上であるような区間における、右端の最小値)
  vector<int> rmin(n + 1, INF);
  rrep (x, n) {
    rmin[x] = rmin[x + 1];
    if (!l2rs[x].empty()) chmin(rmin[x], l2rs[x][0]);
  }

  auto q = input<int>();
  rep (_, q) {
    auto a = input<int>() - 1, b = input<int>();
    int c = H[{a, b}];
    if (c == 2) {
      yes();
    }
    else if (c == 1) {
      yesno(rmin[a] < b || rmin[a + 1] <= b);
    }
    else {
      bool ok = false;
      if (!l2rs[a].empty() && !r2ls[b].empty()) {
        int i = ranges::lower_bound(l2rs[a], b + 1) - l2rs[a].begin() - 1;
        int j = ranges::lower_bound(r2ls[b], a) - r2ls[b].begin();
        if (i >= 0 && j < r2ls[b].size() && l2rs[a][i] >= r2ls[b][j]) ok = true;
      }
      yesno(ok);
    }
  }
}
