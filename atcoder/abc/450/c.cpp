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

class union_find {
  int n;
  vector<int> p;

 public:
  union_find(int n = 0) {
    build(n);
  }
  void build(int n) {
    this->n = n;
    p.assign(n, -1);
  }
  int find(int u) {
    return p[u] < 0 ? u : p[u] = find(p[u]);
  }
  void unite(int u, int v) {
    u = find(u);
    v = find(v);
    if (u != v) {
      if (p[v] < p[u]) swap(u, v);
      p[u] += p[v];
      p[v] = u;
      n--;
    }
  }
  bool is_same(int u, int v) {
    return find(u) == find(v);
  }
  int size() const {
    return n;
  }
  int size(int u) {
    return -p[find(u)];
  }
};

int main() {
  int h, w;
  cin >> h >> w;
  vector<string> B(h);
  rep (i, h) cin >> B[i];

  union_find U(h * w);
  rep (i, h)
    rep (j, w)
      if (B[i][j] == '.') {
        if (i < h - 1 && B[i + 1][j] == '.') U.unite(i * w + j, (i + 1) * w + j);
        if (j < w - 1 && B[i][j + 1] == '.') U.unite(i * w + j, i * w + (j + 1));
      }

  set<int> S;
  rep (i, 1, h - 1) {
    rep (j, 1, w - 1) {
      if (B[i][j] == '.') {
        S.emplace(U.find(i * w + j));
      }
    }
  }
  rep (i, h) {
    rep (j, w) {
      if (B[i][j] == '.' && (i == 0 || i == h - 1 || j == 0 || j == w - 1)) {
        S.erase(U.find(i * w + j));
      }
    }
  }
  cout << S.size() << endl;

  return 0;
}
