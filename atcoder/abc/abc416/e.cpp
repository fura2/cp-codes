#include "template/template.hpp"

// #define MULTI_TESTCASE
#include "template/main.hpp"

void testcase() {
  auto n = input<int>(), m = input<int>();
  vector d(n + 1, vector(n + 1, LINF));
  rep (u, n + 1) d[u][u] = 0;
  rep (i, m) {
    auto u = input<int>() - 1, v = input<int>() - 1;
    lint c = input<lint>();
    chmin(d[u][v], 2 * c);
    chmin(d[v][u], 2 * c);
  }
  auto k = input<int>();
  auto c_air = input<lint>();
  rep (i, k) {
    auto u = input<int>() - 1;
    chmin(d[u][n], c_air);
    chmin(d[n][u], c_air);
  }

  rep (w, n + 1)
    rep (u, n + 1)
      rep (v, n + 1) chmin(d[u][v], d[u][w] + d[w][v]);

  auto q = input<int>();
  rep (_, q) {
    auto t = input<int>();
    if (t == 1) {
      auto u = input<int>() - 1, v = input<int>() - 1;
      auto c = input<lint>();
      chmin(d[u][v], 2 * c);
      chmin(d[v][u], 2 * c);
      rep (i, n + 1) {
        rep (j, n + 1) {
          chmin(d[i][j], d[i][u] + d[u][v] + d[v][j]);
          chmin(d[i][j], d[i][v] + d[v][u] + d[u][j]);
        }
      }
    }
    else if (t == 2) {
      auto u = input<int>() - 1;
      chmin(d[u][n], c_air);
      chmin(d[n][u], c_air);
      rep (i, n + 1) {
        rep (j, n + 1) {
          chmin(d[i][j], d[i][u] + d[u][n] + d[n][j]);
          chmin(d[i][j], d[i][n] + d[n][u] + d[u][j]);
        }
      }
    }
    else {
      lint ans = 0;
      rep (u, n)
        rep (v, u + 1, n)
          if (d[u][v] < LINF) ans += d[u][v];
      output(ans);
    }
  }
}
