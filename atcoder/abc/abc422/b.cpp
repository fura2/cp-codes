#include "template/template.hpp"

// #define MULTI_TESTCASE
#include "template/main.hpp"
#include "util/grid.hpp"

void testcase() {
  auto h = input<int>(), w = input<int>();
  auto G = input<Grid>(h, w);
  rep (i, h) {
    rep (j, w) {
      if (G[i][j] == '.') continue;
      int cnt = 0;
      for (auto [x, y]: G.neighbors4(i, j)) {
        if (G[x][y] == '#') cnt++;
      }
      if (cnt != 2 && cnt != 4) {
        no();
        return;
      }
    }
  }
  yes();
}
