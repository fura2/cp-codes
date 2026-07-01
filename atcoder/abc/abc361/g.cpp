#include "template/template.hpp"

// #define MULTI_TESTCASE
#include "template/main.hpp"

struct Interval {
  int id, row, l, r;
};

void testcase() {
  auto n = input<int>();
  int m = 2e5 + 3;
  vector<vector<int>> P(m);
  rep (i, n) {
    auto c = input<int>() + 1;
    auto r = input<int>() + 1;
    P[r].emplace_back(c);
  }
  rep (i, m) {
    ranges::sort(P[i]);
    P[i].emplace_back(m + 2);
  }

  vector<vector<Interval>> I(m);  // row -> intervals
  int k = 0;
  rep (i, m) {
    int pre = 0;
    for (int c: P[i]) {
      if (pre < c) {
        I[i].emplace_back(k++, i, pre, c);
      }
      pre = c + 1;
    }
  }

  vector<bool> vis(k);
  queue<Interval> Q;
  vis[0] = true;
  Q.emplace(I[0][0]);
  while (!Q.empty()) {
    auto iv = Q.front();
    Q.pop();

    for (int d: {-1, 1}) {
      int row = iv.row + d;
      if (row < 0 || m <= row) continue;

      auto it = ranges::upper_bound(I[row], iv.l, {}, &Interval::r);
      while (it != I[row].end() && it->l < iv.r) {
        int v = it->id;
        if (!vis[v]) {
          vis[v] = true;
          Q.emplace(*it);
        }
        ++it;
      }
    }
  }

  lint ans = 0;
  rep (i, m)
    for (auto iv: I[i])
      if (!vis[iv.id]) ans += iv.r - iv.l;
  output(ans);
}
