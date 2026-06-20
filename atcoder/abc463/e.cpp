#include "template/template.hpp"

// #define MULTI_TESTCASE

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

template <class T>
vector<T> Dijkstra(const weighted_graph<T>& G, int s) {
  constexpr T INF = ::LINF;

  int n = G.size();
  vector<T> d(n, INF);
  d[s] = T{};
  priority_queue<pair<T, int>, vector<pair<T, int>>, greater<>> Q;
  Q.emplace(T{}, s);
  while (!Q.empty()) {
    T d0;
    int u;
    tie(d0, u) = Q.top();
    Q.pop();
    if (d0 > d[u]) continue;
    for (const auto& [v, wt]: G[u]) {
      if (d[v] > d[u] + wt) {
        d[v] = d[u] + wt;
        Q.emplace(d[v], v);
      }
    }
  }
  return d;
}

void testcase() {
  int n = input();
  int m = input();
  lint y = input();
  weighted_graph<lint> G(n);
  rep (i, m) {
    int u = input();
    int v = input();
    lint t = input();
    u--;
    v--;
    add_undirected_edge(G, u, v, t);
  }
  vector<lint> x = input(n);

  auto d0 = Dijkstra(G, 0);
  int u_min = 0;
  rep (u, n) {
    if (d0[u] + x[u] < d0[u_min] + x[u_min]) u_min = u;
  }

  rep (u, n) {
    add_undirected_edge(G, u_min, u, x[u_min] + y + x[u]);
  }
  auto d = Dijkstra(G, u_min);

  vector<lint> ans = d0;
  rep (u, n) {
    chmin(ans[u], d0[u_min] + d[u]);
  }
  ans.erase(ans.begin());
  output(ans);
}

int main() {
#ifndef MULTI_TESTCASE
  testcase();
#else
  int t = input();
  rep (i, t) {
    std::clog << "\033[36mCase #" << i + 1 << "\033[0m" << std::endl;
    testcase();
  }
#endif
  return 0;
}
