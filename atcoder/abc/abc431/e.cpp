#include "template/template.hpp"

#define MULTI_TESTCASE
#include "template/main.hpp"
#include "util/grid.hpp"

void testcase() {
  auto h = input<int>(), w = input<int>();
  auto G = input<Grid>(h, w);

  vector d(4, vector(h, vector(w, INF)));
  deque<tuple<int, int, int, int>> Q;
  d[0][0][0] = 0;
  Q.emplace_back(0, 0, 0, 0);
  while (!Q.empty()) {
    auto [d0, k, x, y] = Q.front();
    Q.pop_front();
    if (d0 != d[k][x][y]) continue;

    rep (k2, 4) {
      if ((k2 - k + 4) % 4 == 2) continue;

      int cost = 1;
      if (G[x][y] == 'A') {
        if (k == k2) cost = 0;
      }
      else if (G[x][y] == 'B') {
        if ((k == 0 && k2 == 3) || (k == 1 && k2 == 2) || (k == 2 && k2 == 1) ||
            (k == 3 && k2 == 0))
          cost = 0;
      }
      else {
        if ((k == 0 && k2 == 1) || (k == 1 && k2 == 0) || (k == 2 && k2 == 3) ||
            (k == 3 && k2 == 2))
          cost = 0;
      }

      int x2 = x + Grid::dx4[k2];
      int y2 = y + Grid::dy4[k2];
      if (G.contains(x2, y2) && d[k2][x2][y2] > d[k][x][y] + cost) {
        d[k2][x2][y2] = d[k][x][y] + cost;
        if (cost == 0) {
          Q.emplace_front(d[k2][x2][y2], k2, x2, y2);
        }
        else {
          Q.emplace_back(d[k2][x2][y2], k2, x2, y2);
        }
      }
    }
  }

  int ans;
  if (G[h - 1][w - 1] == 'A') {
    ans = min(d[0][h - 1][w - 1], d[3][h - 1][w - 1] + 1);
  }
  else if (G[h - 1][w - 1] == 'B') {
    ans = min(d[0][h - 1][w - 1] + 1, d[3][h - 1][w - 1]);
  }
  else {
    ans = min(d[0][h - 1][w - 1] + 1, d[3][h - 1][w - 1] + 1);
  }
  output(ans);
}
