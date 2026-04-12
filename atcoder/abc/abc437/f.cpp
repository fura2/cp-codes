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

template<class M>
class segment_tree {
  int n, sz;
  vector<M> seg;

 public:
  segment_tree(int n = 0) {
    build(n);
  }
  template<class T>
  segment_tree(const vector<T>& a) {
    build(a);
  }

  void build(int n) {
    this->n = n;
    for (sz = 1; sz < n; sz <<= 1);
    seg.assign(2 * sz, M());
  }

  template<class T>
  void build(const vector<T>& a) {
    build(a.size());
    rep (i, a.size()) seg[sz + i] = a[i];
    for (int i = sz - 1; i > 0; i--) {
      seg[i] = seg[2 * i] * seg[2 * i + 1];
    }
  }

  const M& operator[](int i) const {
    return seg[sz + i];
  }

  void update(int i, const M& x) {
    i += sz;
    seg[i] = x;
    for (i >>= 1; i > 0; i >>= 1) seg[i] = seg[2 * i] * seg[2 * i + 1];
  }

  M product(int l, int r) const {
    M lcum, rcum;
    for (int a = l + sz, b = r + sz; a < b; a >>= 1, b >>= 1) {
      if (a & 1) lcum = lcum * seg[a++];
      if (b & 1) rcum = seg[--b] * rcum;
    }
    return lcum * rcum;
  }

  template<class N, class F>
  N operate(int l, int r, const F& f) {
    N lcum, rcum;
    for (int a = l + sz, b = r + sz; a < b; a >>= 1, b >>= 1) {
      if (a & 1) lcum = lcum * f(seg[a++]);
      if (b & 1) rcum = f(seg[--b]) * rcum;
    }
    return lcum * rcum;
  }

  template<class F>
  int max_right(int l, const F& f) const {
    if (l == n) return n;
    M cum;
    auto dfs = [&](auto&& dfs, int a, int b, int u) {
      if (a == b - 1) {
        cum = cum * seg[u];
        return f(cum) ? b : a;
      }

      int c = (a + b) / 2;
      if (c <= l) {
        return dfs(dfs, c, b, 2 * u + 1);
      }
      if (l <= a && f(cum * seg[u])) {
        cum = cum * seg[u];
        return b;
      }

      int idx = dfs(dfs, a, c, 2 * u);
      if (idx < c) return idx;
      return dfs(dfs, c, b, 2 * u + 1);
    };
    return min(dfs(dfs, 0, sz, 1), n);
  }

  template<class F>
  int min_left(int r, const F& f) const {
    if (r == 0) return 0;
    M cum;
    auto dfs = [&](auto&& dfs, int a, int b, int u) {
      if (a == b - 1) {
        cum = seg[u] * cum;
        return f(cum) ? a : b;
      }

      int c = (a + b) / 2;
      if (r <= c) {
        return dfs(dfs, a, c, 2 * u);
      }
      if (b <= r && f(seg[u] * cum)) {
        cum = seg[u] * cum;
        return a;
      }

      int idx = dfs(dfs, c, b, 2 * u + 1);
      if (idx > c) return idx;
      return dfs(dfs, a, c, 2 * u);
    };
    return dfs(dfs, 0, sz, 1);
  }
};

template<class T>
class max_monoid {
  T a;

 public:
  max_monoid(const T& val = numeric_limits<T>::min()): a(val) {}
  max_monoid operator*(const max_monoid& x) const {
    return max(a, x.a);
  }
  T& get() {
    return a;
  }
  const T& get() const {
    return a;
  }
};

template<class T>
class min_monoid {
  T a;

 public:
  min_monoid(const T& val = numeric_limits<T>::max()): a(val) {}
  min_monoid operator*(const min_monoid& x) const {
    return min(a, x.a);
  }
  T& get() {
    return a;
  }
  const T& get() const {
    return a;
  }
};

int main() {
  int n, q;
  cin >> n >> q;
  vector<lint> x(n), y(n);
  rep (i, n) cin >> x[i] >> y[i];

  vector<lint> sum(n), dif(n);
  rep (i, n) {
    sum[i] = x[i] + y[i];
    dif[i] = x[i] - y[i];
  }
  segment_tree<max_monoid<lint>> Ssum_max(sum), Sdif_max(dif);
  segment_tree<min_monoid<lint>> Ssum_min(sum), Sdif_min(dif);

  rep (_, q) {
    int t;
    cin >> t;
    if (t == 1) {
      int i;
      lint a, b;
      cin >> i >> a >> b;
      i--;
      Ssum_max.update(i, a + b);
      Sdif_max.update(i, a - b);
      Ssum_min.update(i, a + b);
      Sdif_min.update(i, a - b);
    }
    else {
      int l, r;
      lint a, b;
      cin >> l >> r >> a >> b;
      l--;
      cout << max({
          Ssum_max.product(l, r).get() - (a + b),
          (a + b) - Ssum_min.product(l, r).get(),
          Sdif_max.product(l, r).get() - (a - b),
          (a - b) - Sdif_min.product(l, r).get(),
      }) << endl;
    }
  }
  return 0;
}
