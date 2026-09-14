#include "template/template.hpp"

#define MULTI_TESTCASE
#include "template/main.hpp"

template <class T>
struct edge {
  int to;
  T wt;
  edge(int to, const T& wt): to(to), wt(wt) {
  }
};
template <class T>
using weighted_graph = vector<vector<edge<T>>>;

template <class T>
void add_undirected_edge(weighted_graph<T>& G, int u, int v, const T& wt) {
  G[u].emplace_back(v, wt);
  G[v].emplace_back(u, wt);
}

void testcase() {
  auto n = input<int>();
  auto m = input<int>();
  auto k = input<int>();
  vector<tuple<int, int, int>> E(m);
  rep (i, m) {
    int u = input<int>() - 1;
    int v = input<int>() - 1;
    int c = input<int>();
    E[i] = {u, v, c};
  }

  weighted_graph<int> G(n);
  rep (i, m) {
    auto [u, v, c] = E[i];
    add_undirected_edge(G, u, v, i);
  }

  set<int> F1;
  {
    priority_queue<tuple<int, int, int>> Q;  // -cost, v, edge idx
    vector<bool> vis(n);
    Q.emplace(0, 0, -1);
    while (!Q.empty()) {
      auto [negc, u, i] = Q.top();
      int c = -negc;
      Q.pop();
      if (vis[u]) continue;

      if (i != -1 && c == 1) {
        F1.emplace(i);
      }
      vis[u] = true;

      for (auto e: G[u]) {
        int v = e.to, j = e.wt;
        if (vis[v]) continue;
        Q.emplace(-get<2>(E[j]), v, j);
      }
    }
  }

  if (k < F1.size()) {
    output(-1);
    return;
  }

  set<int> F2, H;
  {
    priority_queue<tuple<int, int, int>> Q;  // cost, v, edge idx
    vector<bool> vis(n);
    Q.emplace(0, 0, -1);
    while (!Q.empty()) {
      auto [c, u, i] = Q.top();
      Q.pop();
      if (vis[u]) continue;

      if (i != -1) {
        if (c == 1 && F1.size() + F2.size() == k) continue;
        if (c == 1) {
          F2.emplace(i);
        }
        else if (c == 0) {
          H.emplace(i);
        }
      }
      vis[u] = true;

      for (auto e: G[u]) {
        int v = e.to, j = e.wt;
        if (vis[v]) continue;
        int c2 = get<2>(E[j]);
        if (F1.contains(j)) c2 = 2;
        Q.emplace(c2, v, j);
      }
    }
  }

  assert(F1.size() + F2.size() + H.size() == n - 1);
  assert(F1.size() + F2.size() <= k);
  if (F1.size() + F2.size() < k) {
    output(-1);
    return;
  }
  for (int i: F1) cout << i + 1 << " ";
  for (int i: F2) cout << i + 1 << " ";
  for (int i: H) cout << i + 1 << " ";
  cout << "\n";
}
