#include "template/template.hpp"

// #define MULTI_TESTCASE
#include "template/main.hpp"

struct Interval {
  int id, row, l, r;
};

void testcase() {
  auto h = input<int>();
  auto w = input<int>();
  auto k = input<int>();
  vector<vector<int>> P(h);
  rep (i, k) {
    auto r = input<int>() - 1;
    auto c = input<int>() - 1;
    P[r].emplace_back(c);
  }
  rep (i, h) {
    ranges::sort(P[i]);
    P[i].emplace_back(w);
  }

  vector<vector<Interval>> I(h);  // row -> intervals
  int n = 0;
  rep (i, h) {
    int pre = 0;
    for (int c: P[i]) {
      if (pre < c) {
        I[i].emplace_back(n++, i, pre, c);
      }
      pre = c + 1;
    }
  }

  vector<bool> vis(n);
  queue<Interval> Q;
  vis[0] = true;
  Q.emplace(I[0][0]);
  while (!Q.empty()) {
    auto iv = Q.front();
    Q.pop();

    for (int d: {-1, 1}) {
      int row = iv.row + d;
      if (row < 0 || h <= row) continue;

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
  yesno(vis[n - 1]);
}
