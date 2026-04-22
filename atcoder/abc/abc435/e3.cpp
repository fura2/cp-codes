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

// struct MinMonoid {
//   lint x;
//   MinMonoid(): x{INF} {}
//   MinMonoid(lint x): x{x} {}
//   MinMonoid& operator*=(const MinMonoid& m) {
//     chmin(x, m.x);
//     return *this;
//   }
//   MinMonoid operator*(const MinMonoid& m) const {
//     return MinMonoid{*this} *= m;
//   }
//   bool operator==(const MinMonoid& m) const {
//     return x == m.x;
//   }
// };

struct X {
  lint x; // 区間上の値の和
  int w; // 区間の長さ
  X(): x{}, w{} {}
  X(lint x, int w): x{x}, w{w} {}
  X& operator*=(const X& m) {
    x += m.x;
    w += m.w;
    return *this;
  }
  X operator*(const X& m) const {
    return X{*this} *= m;
  }
  bool operator==(const X& m) const {
    return x == m.x && w == m.w;
  }
};

struct FindLastMonoid {
  optional<lint> x;
  FindLastMonoid(): x(nullopt) {}
  FindLastMonoid(lint x): x(x) {}
  FindLastMonoid& operator*=(const FindLastMonoid& m) {
    if (m.x.has_value()) x = m.x;
    return *this;
  }
  FindLastMonoid operator*(const FindLastMonoid& m) const {
    return FindLastMonoid{*this} *= m;
  }
  bool operator==(const FindLastMonoid& m) const {
    return x == m.x;
  }
};

// MinMonoid action(const MinMonoid& x, const FindLastMonoid& m) {
//   return m.x.value_or(x.x);
// }

X action(const X& x, const FindLastMonoid& m) {
  if (m.x.has_value()) {
    return {m.x.value() * x.w, x.w};
  }
  return x;
}

template<typename X, typename M, auto f>
class LazySegmentTree {
 public:
  LazySegmentTree(int n): e{}, id{} {
    this->n = bit_ceil<unsigned int>(n);
    x.assign(2 * this->n, e);
    m.assign(2 * this->n, id);
  }

  LazySegmentTree(const vector<X>& v): e{}, id{} {
    this->n = bit_ceil(v.size());
    x.assign(2 * this->n, e);
    m.assign(2 * this->n, id);
    rep (i, v.size()) x[n + i] = v[i];
    for (int i = n - 1; i >= 1; i--) x[i] = x[2 * i] * x[2 * i + 1];
  }

  void apply(int l, int r, const M& m) {
    this->apply(1, 0, n, l, r, m);
  }

  X product(int l, int r) {
    return this->product(1, 0, n, l, r);
  }

 private:
  int n;
  vector<X> x;
  vector<M> m;
  const X e;
  const M id;

  // 不変条件: この関数の実行後はつねに m[u] == id
  void apply(int u, int a, int b, int l, int r, const M& m_) {
    propagate(u);
    if (b <= l || r <= a) return;
    if (l <= a && b <= r) {
      m[u] = m_;
      propagate(u);
      return;
    }
    int c = (a + b) / 2;
    apply(2 * u, a, c, l, r, m_);
    apply(2 * u + 1, c, b, l, r, m_);
    x[u] = x[2 * u] * x[2 * u + 1];
  }

  X product(int u, int a, int b, int l, int r) {
    propagate(u);
    if (b <= l || r <= a) return e;
    if (l <= a && b <= r) return x[u];
    int c = (a + b) / 2;
    return product(2 * u, a, c, l, r) * product(2 * u + 1, c, b, l, r);
  }

  void propagate(int u) {
    if (m[u] == id) return;
    x[u] = f(x[u], m[u]);
    if (u < n) {
      m[2 * u] *= m[u];
      m[2 * u + 1] *= m[u];
    }
    m[u] = id;
  }

//  public:
//   void debug() {
//     cout << "-- x --" << endl;
//     rep (u, 1, 2 * n) {
//       cout << x[u].x << " ";
//       if (u + 1 == bit_ceil(u + 1u)) cout << endl;
//     }
//     cout << "-- m --" << endl;
//     rep (u, 1, 2 * n) {
//       cout << m[u].x.value_or(-1) << " ";
//       if (u + 1 == bit_ceil(u + 1u)) cout << endl;
//     }
//   }
};

int main() {
  int n, q;
  cin >> n >> q;
  vector<int> l(q), r(q);
  rep (i, q) cin >> l[i] >> r[i], l[i]--;

  vector<int> xs = {0, n};
  rep (i, q) {
    xs.emplace_back(l[i]);
    xs.emplace_back(r[i]);
  }
  sort(all(xs));
  xs.erase(unique(all(xs)), xs.end());
  int m = xs.size();

  vector<int> a(q), b(q);
  rep (i, q) {
    a[i] = lower_bound(all(xs), l[i]) - xs.begin();
    b[i] = lower_bound(all(xs), r[i]) - xs.begin();
  }

  vector<X> init(m - 1);
  rep (i, m - 1) {
    init[i] = {xs[i + 1] - xs[i], 1};
  }
  LazySegmentTree<X, FindLastMonoid, action> S{init};
  rep (i, q) {
    S.apply(a[i], b[i], 0);
    cout << S.product(0, m - 1).x << "\n";
  }

  return 0;
}
