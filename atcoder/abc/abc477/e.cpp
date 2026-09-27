#include "template/template.hpp"

// #define MULTI_TESTCASE
#include "graph/weighted_graph.hpp"
#include "template/main.hpp"

vector<lint> dijkstra(const WeightedGraph<lint>& G, int s) {
  int n = G.num_vertices();
  vector<lint> d(n, LINF);
  priority_queue<pair<lint, int>> Q;
  d[s] = 0;
  Q.emplace(0, s);
  while (!Q.empty()) {
    auto [du, u] = Q.top();
    Q.pop();
    du *= -1;
    if (du > d[u]) continue;
    for (const auto& e: G[u]) {
      if (d[e.to] > d[u] + e.cost) {
        d[e.to] = d[u] + e.cost;
        Q.emplace(-d[e.to], e.to);
      }
    }
  }
  return d;
}

void testcase() {
  int n = input<int>(), q = input<int>();
  auto a = input<vector<lint>>(n), b = input<vector<lint>>(n);

  WeightedGraph<lint> G(n + 1, 2 * n);
  rep (u, n) {
    G.add_edge(u, (u + 1) % n, a[u]);
    G.add_edge(u, n, b[u]);
  }
  auto d = dijkstra(G, n);

  rep (i, n) {
    a.emplace_back(a[i]);
  }
  vector<lint> cum(2 * n + 1);
  rep (i, 2 * n) cum[i + 1] = cum[i] + a[i];

  rep (_, q) {
    int s = input<int>() - 1, t = input<int>() - 1;
    if (s > t) swap(s, t);
    if (t == n) {
      output(d[s]);
    }
    else {
      output(min({d[s] + d[t], cum[t] - cum[s], cum[n + s] - cum[t]}));
    }
  }
}
