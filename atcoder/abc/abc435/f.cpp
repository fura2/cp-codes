#ifndef TEMPLATE_HPP
#define TEMPLATE_HPP

#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>

// clang-format off
#define impl_overload4(a, b, c, d, e, ...) e

#define impl_rep4(i, a, b, c) for (int i = (a); i < (b); i += (c))
#define impl_rep3(i, a, b) impl_rep4(i, a, b, 1)
#define impl_rep2(i, n) impl_rep3(i, 0, n)
#define impl_rep1(n) for (int _ = 0; _ < (n); ++_)
#define rep(...) impl_overload4(__VA_ARGS__, impl_rep4, impl_rep3, impl_rep2, impl_rep1)(__VA_ARGS__)

#define impl_rrep4(i, a, b, c) for (int i = (b) - 1; i >= (a); i -= (c))
#define impl_rrep3(i, a, b) impl_rrep4(i, a, b, 1)
#define impl_rrep2(i, n) impl_rrep3(i, 0, n)
#define rrep(...) impl_overload4(__VA_ARGS__, impl_rrep4, impl_rrep3, impl_rrep2)(__VA_ARGS__)

#define all(v) std::begin(v), std::end(v)

template<typename T>
constexpr int bit(T x, unsigned int k) { return (x >> k) & 1; }

template<typename T>
constexpr bool chmax(T& a, const T& b) { return a < b ? a = b, true : false; }
template<typename T>
constexpr bool chmin(T& a, const T& b) { return a > b ? a = b, true : false; }

constexpr void yesno(bool b) { std::cout << (b ? "Yes" : "No") << "\n"; }
constexpr void yes() { yesno(true); }
constexpr void no() { yesno(false); }

struct Setup {
  Setup() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout << std::fixed << std::setprecision(10);
  }
} setup;
// clang-format on

#ifdef LOCAL
#include "template_local.hpp"
#else
#define show(...) ((void)0)
#endif

using lint = long long;

using namespace std;

#endif // TEMPLATE_HPP

template<class T>
class Cartesian_tree {
  vector<T> a;
  int rt;
  vector<int> p, l, r;

 public:
  Cartesian_tree(const vector<T>& a = {}) {
    build(a);
  }

  void build(const vector<T>& a) {
    this->a = a;
    int n = a.size();
    rt = 0;
    p.assign(n, -1);
    l.assign(n, -1);
    r.assign(n, -1);

    for (int u = 1; u < n; u++) {
      int v = u - 1;
      bool top = false;
      while (a[v] > a[u]) {
        if (p[v] == -1) {
          top = true;
          break;
        }
        v = p[v];
      }
      if (top) {
        p[v] = u;
        l[u] = v;
        rt = u;
      }
      else {
        p[u] = v;
        if (r[v] != -1) p[r[v]] = u;
        l[u] = r[v];
        r[v] = u;
      }
    }
  }
  const T& operator[](int u) const {
    return a[u];
  }
  int root() const {
    return rt;
  }
  int parent(int u) const {
    return p[u];
  }
  int left(int u) const {
    return l[u];
  }
  int right(int u) const {
    return r[u];
  }
};

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  rep (i, n) cin >> a[i], a[i] *= -1;

  Cartesian_tree T(a);

  auto dfs = [&](auto dfs, int u) -> lint {
    int l = T.left(u), r = T.right(u);
    if (l == -1 && r == -1) return 0;
    if (l == -1) return abs(r - u) + dfs(dfs, r);
    if (r == -1) return abs(l - u) + dfs(dfs, l);
    return max(abs(r - u) + dfs(dfs, r), abs(l - u) + dfs(dfs, l));
  };
  cout << dfs(dfs, T.root()) << endl;

  return 0;
}
