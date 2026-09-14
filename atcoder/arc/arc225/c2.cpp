#include "template/template.hpp"

#define MULTI_TESTCASE
#include "graph/weighted_edge.hpp"
#include "graph/weighted_graph.hpp"
#include "template/main.hpp"

void testcase() {
  auto n = input<int>();
  auto m = input<int>();
  auto k = input<int>();
  auto G = input<WeightedGraph<int>>(n, m, 1);

  set<int> F1;
  {
    vector<bool> vis(n);
    priority_queue<WeightedEdge<int>,
                   vector<WeightedEdge<int>>,
                   decltype([](const auto& e, const auto& f) {
                     return e.cost > f.cost;
                   })>
        Q;  // min heap
    Q.emplace(-1, 0, 0);
    while (!Q.empty()) {
      auto e = Q.top();
      Q.pop();
      int u = e.to;
      if (vis[u]) continue;
      vis[u] = true;

      if (e.from != -1 && e.cost == 1) F1.emplace(e.id);

      for (const auto& f: G[u]) {
        if (!vis[f.to]) Q.emplace(f);
      }
    }
  }

  if (k < F1.size()) {
    output(-1);
    return;
  }

  set<int> F2, H;
  {
    vector<bool> vis(n);
    priority_queue<WeightedEdge<int>,
                   vector<WeightedEdge<int>>,
                   decltype([](const auto& e, const auto& f) {
                     return e.cost < f.cost;
                   })>
        Q;  // max heap
    Q.emplace(-1, 0, 0);
    while (!Q.empty()) {
      auto e = Q.top();
      Q.pop();
      int u = e.to;
      if (vis[u]) continue;

      if (e.cost == 1 && F1.size() + F2.size() == k) continue;
      vis[u] = true;

      if (e.from != -1) {
        if (e.cost == 1) {
          F2.emplace(e.id);
        }
        else if (e.cost == 0) {
          H.emplace(e.id);
        }
      }

      for (auto f: G[u]) {
        if (F1.contains(f.id)) f.cost = 2;
        if (!vis[f.to]) Q.emplace(f);
      }
    }
  }

  if (F1.size() + F2.size() < k) {
    output(-1);
    return;
  }

  output(vector(from_range, F1), 1);
  output(vector(from_range, F2), 1);
  output(vector(from_range, H), 1);
}
