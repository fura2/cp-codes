#include "template/template.hpp"

// #define MULTI_TESTCASE
#include "template/main.hpp"
#include "util/grid.hpp"

void testcase() {
  auto h = input<int>(), w = input<int>();
  auto G = input<Grid>(h, w);

  queue<pair<int, int>> Q;
  vector d(h, vector(w, INF)), prev(h, vector(w, -1));
  for (auto [i, j]: G.find_all('E')) {
    Q.emplace(i, j);
    d[i][j] = 0;
  }
  while (!Q.empty()) {
    auto [i, j] = Q.front();
    Q.pop();
    rep (k, 4) {
      int x = i + Grid::dx4[k];
      int y = j + Grid::dy4[k];
      if (!G.contains(x, y) || G[x][y] == '#') continue;
      if (d[x][y] == INF) {
        d[x][y] = d[i][j] + 1;
        prev[x][y] = k;
        Q.emplace(x, y);
      }
    }
  }

  rep (i, h) {
    rep (j, w) {
      if (G[i][j] != '.') continue;
      G[i][j] = "<v>^"[prev[i][j]];
    }
  }
  output(G);
}
