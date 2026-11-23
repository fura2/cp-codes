// solution by color coding

#include "template/template.hpp"

#include <random>

// #define MULTI_TESTCASE
#include "graph/graph.hpp"
#include "template/main.hpp"

void testcase() {
  auto n = input<int>(), m = input<int>();
  auto G = input<Graph>(n, m, 1);
  auto s = input<string>();

  auto rng = mt19937(random_device{}());

  vector<int> W, B;
  rep (u, n) (s[u] == 'S' ? W : B).emplace_back(u);

  vector<int> ans(B.size(), INF);
  rep (_, 30) {
    vector<int> color(W.size());
    rep (i, W.size()) color[i] = rng() % 2;

    vector d(2, vector(n, INF));
    queue<int> Q;
    rep (c, 2) {
      rep (i, W.size())
        if (color[i] == c) {
          d[c][W[i]] = 0;
          Q.emplace(W[i]);
        }
      while (!Q.empty()) {
        int u = Q.front();
        Q.pop();
        for (auto e: G[u]) {
          if (d[c][e.to] < INF) continue;
          d[c][e.to] = d[c][u] + 1;
          Q.emplace(e.to);
        }
      }
    }
    rep (i, B.size()) chmin(ans[i], d[0][B[i]] + d[1][B[i]]);
  }
  output(ans);
}
