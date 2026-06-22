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
void add_directed_edge(weighted_graph<T>& G, int u, int v, const T& wt) {
  G[u].emplace_back(v, wt);
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
  weighted_graph<lint> G(n + 2);
  rep (i, m) {
    int u = input();
    int v = input();
    lint t = input();
    u--;
    v--;
    add_undirected_edge(G, u, v, t);
  }
  vector<lint> x = input(n);
  rep (u, n) {
    add_directed_edge(G, u, n, x[u]);
    add_directed_edge(G, n, n + 1, y);
    add_directed_edge(G, n + 1, u, x[u]);
  }

  vector<lint> d = Dijkstra(G, 0);
  output(vector<lint>(d.begin() + 1, d.end() - 2));
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
