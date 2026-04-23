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

constexpr lint INF = 1LL << 61;

struct AdditionMonoid {
  lint x;
  AdditionMonoid(): x{} {}
  AdditionMonoid(lint x): x{x} {}
  AdditionMonoid& operator*=(const AdditionMonoid& m) {
    x += m.x;
    return *this;
  }
  AdditionMonoid operator*(const AdditionMonoid& m) const {
    return AdditionMonoid{*this} *= m;
  }
  bool operator==(const AdditionMonoid& m) const {
    return x == m.x;
  }
};

struct MinCountMonoid {
  lint x; // 区間上の値の最小値
  lint c; // 最小値の個数
  MinCountMonoid(): x{INF}, c{} {}
  MinCountMonoid(lint x, lint c): x{x}, c{c} {}
  MinCountMonoid& operator*=(const MinCountMonoid& m) {
    if (x == m.x) {
      c += m.c;
    }
    else if (x > m.x) {
      x = m.x;
      c = m.c;
    }
    return *this;
  }
  MinCountMonoid operator*(const MinCountMonoid& m) const {
    return MinCountMonoid{*this} *= m;
  }
  bool operator==(const MinCountMonoid& m) const {
    return x == m.x && c == m.c;
  }
};

MinCountMonoid action(const MinCountMonoid& x, const AdditionMonoid& m) {
  return {x.x + m.x, x.c};
}

template<typename X, typename M, auto f>
class LazySegmentTree {
 public:
  LazySegmentTree(int n): e{}, id{} {
    this->n = bit_ceil<unsigned int>(n);
    x.assign(2 * this->n, e);
    m.assign(2 * this->n, id);
  }

  LazySegmentTree(int n, const X& v): e{}, id{} {
    this->n = bit_ceil<unsigned int>(n);
    x.assign(2 * this->n, e);
    m.assign(2 * this->n, id);
    rep (i, v.size()) x[n + i] = v;
    for (int i = n - 1; i >= 1; i--) x[i] = x[2 * i] * x[2 * i + 1];
  }

  LazySegmentTree(const vector<X>& v): e{}, id{} {
    this->n = bit_ceil(v.size());
    x.assign(2 * this->n, e);
    m.assign(2 * this->n, id);
    rep (i, v.size()) x[n + i] = v[i];
    for (int i = n - 1; i >= 1; i--) x[i] = x[2 * i] * x[2 * i + 1];
  }

  void apply(int l, int r, const M& m) {
    apply(1, 0, n, l, r, m);
  }

  X product(int l, int r) {
    return product(1, 0, n, l, r);
  }

  X product() const {
    return x[1];
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
};

struct Rectangle {
  lint t, l, b, r; // [t, b) x [l, r)
};

lint area_of_union_of_rectangles(vector<Rectangle> R) {
  int n = R.size();
  if (n == 0) return 0;

  vector<lint> X(2 * n);
  rep (i, n) {
    X[2 * i] = R[i].l;
    X[2 * i + 1] = R[i].r;
  }
  ranges::sort(X);
  X.erase(ranges::unique(X).begin(), X.end());
  int m = X.size();

  rep (i, n) {
    R[i].l = ranges::lower_bound(X, R[i].l) - X.begin();
    R[i].r = ranges::lower_bound(X, R[i].r) - X.begin();
  }

  vector<MinCountMonoid> init(m - 1);
  rep (i, m - 1) {
    init[i] = {0, X[i + 1] - X[i]};
  }
  LazySegmentTree<MinCountMonoid, AdditionMonoid, action> S{init};
  vector<tuple<lint, int, int>> E;
  rep (i, n) {
    E.emplace_back(R[i].t, i, 0);
    E.emplace_back(R[i].b, i, 1);
  }
  ranges::sort(E);

  lint res = 0;
  int idx = 0;
  while (idx < E.size()) {
    lint y1 = get<0>(E[idx]), y2 = y1;
    while (idx < E.size()) {
      auto [y, i, t] = E[idx];
      if (y > y1) {
        y2 = y;
        break;
      }
      S.apply(R[i].l, R[i].r, t == 0 ? 1 : -1);
      idx++;
    }

    auto a = S.product();
    res += (X[m - 1] - X[0] - (a.x == 0 ? a.c : 0)) * (y2 - y1);
  }
  return res;
}

int main() {
  lint h, w, a, b;
  int n;
  cin >> h >> w >> a >> b >> n;
  vector<Rectangle> R(n);
  rep (i, n) {
    lint r, c;
    cin >> r >> c;
    r--, c--;
    R[i] = {max(r - a + 1, 0LL),
            max(c - b + 1, 0LL),
            min(r + 1, h - a + 1),
            min(c + 1, w - b + 1)};
  }
  cout << (h - a + 1) * (w - b + 1) - area_of_union_of_rectangles(R) << endl;

  return 0;
}
