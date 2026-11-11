#include "template/template.hpp"

// #define MULTI_TESTCASE
#include "template/main.hpp"
#include "util/grid.hpp"

int h, w;
lint a[20][20];
Grid G;

lint ans;

void dfs(int i, int j) {
  if (i == h) {
    lint res = 0;
    rep (x, h)
      rep (y, w)
        if (G[x][y] == '.') res ^= a[x][y];
    chmax(ans, res);
    return;
  }

  if (j == w) {
    dfs(i + 1, 0);
    return;
  }

  dfs(i, j + 1);
  if (G[i][j] == '.') {
    G[i][j] = '#';
    if (j < w - 1 && G[i][j + 1] == '.') {
      G[i][j + 1] = '#';
      dfs(i, j + 1);
      G[i][j + 1] = '.';
    }
    if (i < h - 1 && G[i + 1][j] == '.') {
      G[i + 1][j] = '#';
      dfs(i, j + 1);
      G[i + 1][j] = '.';
    }
    G[i][j] = '.';
  }
}

void testcase() {
  h = input<int>(), w = input<int>();
  rep (i, h)
    rep (j, w) a[i][j] = input<lint>();

  G = Grid(h, w);
  dfs(0, 0);
  output(ans);
}
