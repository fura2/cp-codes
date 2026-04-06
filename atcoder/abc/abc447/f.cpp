// solution based on rerooting

#ifndef TEMPLATE_HPP
#define TEMPLATE_HPP

#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>

#define impl_overload4(a, b, c, d, e, ...) e
#define impl_overload5(a, b, c, d, e, f, ...) f
#define impl_overload6(a, b, c, d, e, f, g, ...) g
#define impl_overload7(a, b, c, d, e, f, g, h, ...) h

// clang-format off
#define impl_rep4(i, a, b, c) for (int i = (a); i < (b); i += (c))
#define impl_rep3(i, a, b) impl_rep4(i, a, b, 1)
#define impl_rep2(i, n) impl_rep3(i, 0, n)
#define impl_rep1(n) for (int _ = 0; _ < (n); ++_)
#define rep(...) impl_overload4(__VA_ARGS__, impl_rep4, impl_rep3, impl_rep2, impl_rep1)(__VA_ARGS__)

#define impl_rrep4(i, a, b, c) for (int i = (b) - 1; i >= (a); i -= (c))
#define impl_rrep3(i, a, b) impl_rrep4(i, a, b, 1)
#define impl_rrep2(i, n) impl_rrep3(i, 0, n)
#define rrep(...) impl_overload4(__VA_ARGS__, impl_rrep4, impl_rrep3, impl_rrep2)(__VA_ARGS__)
// clang-format on

#define all(v) std::begin(v), std::end(v)
#define rall(v) std::rbegin(v), std::rend(v)

template<typename T>
constexpr int bit(T x, unsigned int k) {
  return (x >> k) & 1;
}

template<typename T>
constexpr bool chmax(T& a, const T& b) {
  return a < b ? a = b, true : false;
}
template<typename T>
constexpr bool chmin(T& a, const T& b) {
  return a > b ? a = b, true : false;
}

void yesno(bool b) {
  std::cout << (b ? "Yes" : "No") << "\n";
}
void yes() {
  yesno(true);
}
void no() {
  yesno(false);
}

struct Setup {
  Setup() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout << std::fixed << std::setprecision(11);
  }
} setup;

#ifdef LOCAL
#include "template_local.hpp"
#else
#define show(...) ((void)0)
#endif

using uint = unsigned int;
using lint = long long;
using ulint = unsigned long long;

using namespace std;

#endif // TEMPLATE_HPP

using graph = vector<vector<int>>;

void add_undirected_edge(graph& G, int u, int v) {
  G[u].emplace_back(v);
  G[v].emplace_back(u);
}

void add_directed_edge(graph& G, int u, int v) {
  G[u].emplace_back(v);
}

int n;
graph T;
vector<int> memo;

int dfs(int u, int p) {
  for (int v: T[u]) {
    if (v == p) continue;
    dfs(v, u);
  }

  int k = ssize(T[u]) - (p == -1 ? 0 : 1);
  if (k <= 1) return memo[u] = 0;
  if (k == 2) return memo[u] = 1;

  int res = 1;
  for (int v: T[u]) {
    if (v == p) continue;
    chmax(res, memo[v] + 1);
  }
  return memo[u] = res;
}

int dfs2(int u, int p, int c) {
  pair<int, int> top2 = {c, 0};
  auto update = [&](int x) {
    if (top2.first < x) {
      top2.second = top2.first;
      top2.first = x;
    }
    else if (top2.second < x) {
      top2.second = x;
    }
  };

  for (int v: T[u]) {
    if (v == p) continue;
    update(memo[v]);
  }

  int res;
  if (T[u].size() <= 1) {
    res = 0;
  }
  else if (T[u].size() == 2) {
    res = 1;
  }
  else if (T[u].size() == 3) {
    res = 1 + top2.first;
  }
  else {
    res = 1 + top2.first + top2.second;
  }

  for (int v: T[u]) {
    if (v == p) continue;

    int c2;
    if (T[u].size() <= 2) {
      c2 = 0;
    }
    else if (T[u].size() == 3) {
      c2 = 1;
    }
    else {
      if (top2.first == memo[v])
        c2 = 1 + top2.second;
      else
        c2 = 1 + top2.first;
    }
    chmax(res, dfs2(v, u, c2));
  }
  return res;
}

void solve() {
  cin >> n;
  T = graph(n);
  rep (i, n - 1) {
    int u, v;
    cin >> u >> v;
    u--;
    v--;
    add_undirected_edge(T, u, v);
  }

  memo.assign(n, -1);
  dfs(0, -1);
  cout << dfs2(0, -1, 0) << endl;
}

int main() {
  int t;
  cin >> t;
  rep (_, t) solve();
  return 0;
}
