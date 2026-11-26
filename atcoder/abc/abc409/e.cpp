#include "template/template.hpp"

// #define MULTI_TESTCASE
#include "graph/weighted_tree.hpp"
#include "template/main.hpp"

void testcase() {
  auto n = input<int>();
  auto a = input<vector<lint>>(n);
  auto T = input<WeightedTree<int>>(n, 1);

  vector<int> deg(n);
  rep (u, n) deg[u] = T.degree(u);

  lint ans = 0;
  vector<bool> del(n);
  queue<int> Q;
  rep (u, n) {
    if (deg[u] == 1) Q.emplace(u);
  }
  while (Q.size() >= 2) {
    int u = Q.front();
    Q.pop();

    int p = -1;
    int cost;
    for (const auto& e: T[u]) {
      if (!del[e.to]) {
        p = e.to;
        cost = e.cost;
        break;
      }
    }
    assert(p != -1);

    for (const auto& e: T[u]) {
      deg[e.to]--;
      if (deg[e.to] == 1) Q.emplace(e.to);
    }
    ans += abs(a[u]) * cost;
    a[p] += a[u];
    del[u] = true;
  }
  output(ans);
}
