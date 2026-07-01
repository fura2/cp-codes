#include "template/template.hpp"

// #define MULTI_TESTCASE
#include "template/main.hpp"

constexpr int dx[] = {0, -1, -1, -1, 0, 1, 1, 1},
              dy[] = {1, 1, 0, -1, -1, -1, 0, 1};

void testcase() {
  auto h = input<int>();
  auto w = input<int>();
  auto k = input<int>();
  set<pair<int, int>> S;
  rep (i, k) {
    auto r = input<int>() - 1;
    auto c = input<int>() - 1;
    S.emplace(r, c);
  }

  set<pair<int, int>> vis;
  queue<pair<int, int>> Q;
  for (auto p: S) {
    if (p.first == 0 || p.second == w - 1) {
      vis.emplace(p);
      Q.emplace(p);
    }
  }
  while (!Q.empty()) {
    auto [x, y] = Q.front();
    Q.pop();
    if (x == h - 1 || y == 0) {
      no();
      return;
    }
    rep (k, 8) {
      int x2 = x + dx[k], y2 = y + dy[k];
      if (!vis.contains({x2, y2}) && S.contains({x2, y2})) {
        vis.emplace(x2, y2);
        Q.emplace(x2, y2);
      }
    }
  }
  yes();
}
