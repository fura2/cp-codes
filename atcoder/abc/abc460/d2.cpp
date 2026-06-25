#include "template/template.hpp"

#include "graph/grid.hpp"

// #define MULTI_TESTCASE

void testcase() {
  auto B = input<Grid>();
  int h = B.height(), w = B.width();

  {
    Grid B2(h, w);
    rep (x, h)
      rep (y, w)
        if (B[x][y] == '#')
          for (auto [x2, y2]: B2.neighbors8(x, y))
            if (B[x2][y2] == '.') B2[x2][y2] = '#';
    B = B2;
  }

  if (B.count('#') == 0) {
    output(B);
    return;
  }

  queue<pair<int, int>> Q;
  vector d(h, vector(w, INF));
  rep (i, h)
    rep (j, w)
      if (B[i][j] == '#') d[i][j] = 0, Q.emplace(i, j);
  while (!Q.empty()) {
    auto [x, y] = Q.front();
    Q.pop();
    for (auto [x2, y2]: B.neighbors8(x, y)) {
      if (d[x2][y2] == INF) {
        d[x2][y2] = d[x][y] + 1;
        Q.emplace(x2, y2);
      }
    }
  }

  rep (i, h)
    rep (j, w) B[i][j] = (d[i][j] % 2 == 0 ? '.' : '#');
  output(B);
}

int main() {
#ifndef MULTI_TESTCASE
  testcase();
#else
  int t = input();
  rep (i, t) {
#ifdef LOCAL
    std::cerr << std::format("\033[36mCase #{}\033[0m\n", i + 1);
#endif
    testcase();
  }
#endif
  return 0;
}
