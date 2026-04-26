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

class mint {
        // static const int MOD=1e9+7;
  static const int MOD = 998244353;
  int x;

 public:
  mint(): x(0) {}
  mint(long long y) {
    x = y % MOD;
    if (x < 0) x += MOD;
  }

  mint& operator+=(const mint& m) {
    x += m.x;
    if (x >= MOD) x -= MOD;
    return *this;
  }
  mint& operator-=(const mint& m) {
    x -= m.x;
    if (x < 0) x += MOD;
    return *this;
  }
  mint& operator*=(const mint& m) {
    x = (long long)x * m.x % MOD;
    return *this;
  }
  mint& operator/=(const mint& m) {
    return *this *= inverse(m);
  }
  mint operator+(const mint& m) const {
    return mint(*this) += m;
  }
  mint operator-(const mint& m) const {
    return mint(*this) -= m;
  }
  mint operator*(const mint& m) const {
    return mint(*this) *= m;
  }
  mint operator/(const mint& m) const {
    return mint(*this) /= m;
  }
  mint operator-() const {
    return -x;
  }

  friend mint inverse(const mint& m) {
    int a = m.x, b = MOD, u = 1, v = 0;
    while (b > 0) {
      int t = a / b;
      a -= t * b;
      swap(a, b);
      u -= t * v;
      swap(u, v);
    }
    return u;
  }

  friend istream& operator>>(istream& is, mint& m) {
    long long t;
    is >> t;
    m = t;
    return is;
  }
  friend ostream& operator<<(ostream& os, const mint& m) {
    return os << m.x;
  }
  int to_int() const {
    return x;
  }

  bool operator==(const mint& m) const = default;
};

mint operator+(long long x, const mint& m) {
  return mint(x) + m;
}
mint operator-(long long x, const mint& m) {
  return mint(x) - m;
}
mint operator*(long long x, const mint& m) {
  return mint(x) * m;
}
mint operator/(long long x, const mint& m) {
  return mint(x) / m;
}

struct AdditionMonoid {
  mint x;
  AdditionMonoid(): x{} {}
  AdditionMonoid(mint x): x{x} {}
  AdditionMonoid& operator*=(const AdditionMonoid& m) {
    x += m.x;
    return *this;
  }
  AdditionMonoid operator*(const AdditionMonoid& m) const {
    return AdditionMonoid{*this} *= m;
  }
  bool operator==(const AdditionMonoid& m) const = default;
};

struct X {
  mint sum1; // 区間上の値の和
  mint sum2; // 区間上の値の二乗和
  int w; // 区間の長さ
  X(): sum1{}, sum2{}, w{} {}
  X(mint sum1, mint sum2, int w): sum1{sum1}, sum2{sum2}, w{w} {}
  X& operator*=(const X& m) {
    sum1 += m.sum1;
    sum2 += m.sum2;
    w += m.w;
    return *this;
  }
  X operator*(const X& m) const {
    return X{*this} *= m;
  }
  bool operator==(const X& m) const = default;
};

X action(const X& x, const AdditionMonoid& m) {
  return {x.sum1 + m.x * x.w, x.sum2 + 2 * m.x * x.sum1 + m.x * m.x * x.w, x.w};
}

template<typename X, typename M, auto f>
class LazySegmentTree {
 public:
  LazySegmentTree(int n): n{n}, e{}, id{} {
    sz = bit_ceil<unsigned int>(n);
    x.assign(2 * sz, e);
    m.assign(2 * sz, id);
  }

  LazySegmentTree(int n, const X& v): n{n}, e{}, id{} {
    sz = bit_ceil<unsigned int>(n);
    x.assign(2 * sz, e);
    m.assign(2 * sz, id);
    rep (i, n) x[sz + i] = v;
    for (int i = sz - 1; i >= 1; i--) x[i] = x[2 * i] * x[2 * i + 1];
  }

  LazySegmentTree(const vector<X>& v): n{v.size()}, e{}, id{} {
    sz = bit_ceil(v.size());
    x.assign(2 * sz, e);
    m.assign(2 * sz, id);
    rep (i, n) x[sz + i] = v[i];
    for (int i = sz - 1; i >= 1; i--) x[i] = x[2 * i] * x[2 * i + 1];
  }

  void apply(int l, int r, const M& m) {
    apply(1, 0, sz, l, r, m);
  }

  X product(int l, int r) {
    return product(1, 0, sz, l, r);
  }

  X product() const {
    return x[1];
  }

 private:
  int n; // raw length
  int sz; // power of 2
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
    if (u < sz) {
      m[2 * u] *= m[u];
      m[2 * u + 1] *= m[u];
    }
    m[u] = id;
  }
};

int main() {
  int n, q;
  cin >> n >> q;

  LazySegmentTree<X, AdditionMonoid, action> S(n, X{0, 0, 1});
  rep (_, q) {
    int l, r, a;
    cin >> l >> r >> a;
    l--;
    S.apply(l, r, mint{a});
    auto res = S.product(l, r);
    cout << (res.sum1 * res.sum1 - res.sum2) / 2 << "\n";
  }

  return 0;
}
