#include "template/template.hpp"

// #define MULTI_TESTCASE
#include "template/main.hpp"
#include "util/grid.hpp"

void testcase() {
  auto h = input<int>(), w = input<int>();
  auto G = input<Grid>(h, w);

  auto [sx, sy] = G.find('S');
  auto [gx, gy] = G.find('G');

  queue<tuple<int, int, int>> Q;
  vector d(2, vector(h, vector(w, INF)));
  d[0][sx][sy] = 0;
  Q.emplace(0, sx, sy);
  while (!Q.empty()) {
    auto [k, x, y] = Q.front();
    Q.pop();
    if (x == gx && y == gy) {
      output(d[k][x][y]);
      return;
    }
    for (auto [x2, y2]: G.neighbors4(x, y)) {
      if (G[x2][y2] == '#') continue;
      if (k == 0 && G[x2][y2] == 'x') continue;
      if (k == 1 && G[x2][y2] == 'o') continue;
      int k2 = (G[x2][y2] == '?' ? 1 - k : k);
      if (d[k2][x2][y2] < INF) continue;
      d[k2][x2][y2] = d[k][x][y] + 1;
      Q.emplace(k2, x2, y2);
    }
  }
  output(-1);
}
