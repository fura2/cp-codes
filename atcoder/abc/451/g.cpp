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

template<class T>
struct edge {
  int from, to;
  T wt;
  edge() = default;
  edge(int from, int to, const T& wt): from(from), to(to), wt(wt) {}
};
template<class T>
using weighted_graph = vector<vector<edge<T>>>;

template<class T>
void add_undirected_edge(weighted_graph<T>& G, int u, int v, const T& wt) {
  G[u].emplace_back(u, v, wt);
  G[v].emplace_back(v, u, wt);
}

class BinaryTrie {
  struct Node {
    Node* ch[2] = {nullptr, nullptr};
    int num = 0;
  };

  Node root;

 public:
  BinaryTrie() = default;

  void add(lint x) {
    Node* p = &this->root;
    rrep (i, 32) {
      p->num++;
      auto& nxt = p->ch[bit(x, i)];
      if (!nxt) nxt = new Node();
      p = nxt;
    }
    p->num++;
  }

  // count |{x in S | x xor c <= k }|, where S is the set of added elements
  int query(lint c, lint k) const {
    auto p = &this->root;
    int res = 0;
    rrep (i, 32) {
      int kb = bit(k, i);
      int cb = bit(c, i);
      if (kb == 0) {
        if (!p->ch[cb]) return res;
        p = p->ch[cb];
      }
      else {
        if (p->ch[cb]) res += p->ch[cb]->num;
        if (!p->ch[cb ^ 1]) return res;
        p = p->ch[cb ^ 1];
      }
    }
    res += p->num;
    return res;
  }
};

vector<lint> xor_basis(vector<lint> S) {
  vector<lint> B;
  for (auto x: S) {
    for (auto y: B) chmin(x, x ^ y);
    if (x != 0) B.emplace_back(x);
  }
  return B;
}

void solve() {
  int n, m, k;
  cin >> n >> m >> k;
  weighted_graph<lint> G(n);
  vector<edge<lint>> E(m);
  rep (i, m) {
    int u, v;
    lint c;
    cin >> u >> v >> c;
    u--, v--;
    add_undirected_edge(G, u, v, c);
    E[i] = {u, v, c};
  }

  vector<lint> d(n, -1);
  d[0] = 0;
  auto dfs = [&](auto dfs, int u) -> void {
    for (const auto& e: G[u]) {
      if (d[e.to] == -1) {
        d[e.to] = d[u] ^ e.wt;
        dfs(dfs, e.to);
      }
    }
  };
  dfs(dfs, 0);

  vector<lint> B(m);
  rep (i, m) {
    auto [u, v, wt] = E[i];
    B[i] = d[u] ^ d[v] ^ wt;
  }
  B = xor_basis(B);

  // f(x) = min{ x xor b | b in B }
  auto f = [&](lint x) {
    for (auto b: B) chmin(x, x ^ b);
    return x;
  };

  // X[u] = min{ 0-u パスの重み xor 任意個のサイクルの重み }
  vector<lint> X(n);
  rep (u, n) X[u] = f(d[u]);

  lint ans = 0;
  BinaryTrie T;
  rep (u, n) {
    ans += T.query(X[u], k);
    T.add(X[u]);
  }
  cout << ans << endl;
}

int main() {
  int t;
  cin >> t;
  rep (_, t) solve();
  return 0;
}
