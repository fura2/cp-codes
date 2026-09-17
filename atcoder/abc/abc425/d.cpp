#include "template/template.hpp"

// #define MULTI_TESTCASE
#include "template/main.hpp"
#include "util/grid.hpp"

void testcase() {
  auto h = input<int>(), w = input<int>();
  auto G = input<Grid>(h, w);

  vector vis(h, vector(w, false));
  queue<pair<int, int>> Q;
  rep (i, h)
    rep (j, w)
      if (G[i][j] == '#' && !vis[i][j]) {
        vis[i][j] = true;
        Q.emplace(i, j);
      }
  while (true) {
    set<pair<int, int>> S;
    while (!Q.empty()) {
      auto [i, j] = Q.front();
      Q.pop();
      for (auto [x, y]: G.neighbors4(i, j)) {
        if (G[x][y] == '#') continue;
        int cnt = 0;
        for (auto [x2, y2]: G.neighbors4(x, y)) {
          if (G[x2][y2] == '#') cnt++;
        }
        if (cnt == 1) {
          S.emplace(x, y);
        }
      }
    }

    for (auto [i, j]: S) {
      assert(!vis[i][j]);
      vis[i][j] = true;
      G[i][j] = '#';
      Q.emplace(i, j);
    }
    if (S.empty()) break;
  }

  output(G.count('#'));
}
