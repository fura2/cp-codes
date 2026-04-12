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
    std::cout << std::fixed << std::setprecision(11);
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

mint pow(mint m, long long k) {
  mint res = 1;
  for (; k > 0; k >>= 1, m *= m)
    if (k & 1) res *= m;
  return res;
}

mint factorial(int n) {
  static vector<mint> memo = {1};
  if (memo.size() <= n) {
    int k = memo.size();
    memo.resize(n + 1);
    for (; k <= n; k++) memo[k] = memo[k - 1] * k;
  }
  return memo[n];
}

mint factorial_inverse(int n) {
  static vector<mint> memo = {1};
  if (memo.size() <= n) {
    int k = memo.size();
    memo.resize(n + 1);
    memo[n] = inverse(factorial(n));
    for (int i = n; i > k; i--) memo[i - 1] = memo[i] * i;
  }
  return memo[n];
}

mint choose(int n, int k, int type = 0) {
  if (k == 0) return 1;
  if (n < k) return 0;
  if (type == 0) {
    return factorial(n) * factorial_inverse(k) * factorial_inverse(n - k);
  }
  else {
    if (k > n - k) k = n - k;
    mint res = factorial_inverse(k);
    rep (i, k) res *= n - i;
    return res;
  }
}

mint multichoose(int n, int k, int type = 0) {
  return choose(n + k - 1, k, type);
}

template<class G>
class Fenwick_tree_dual {
  vector<G> a;

 public:
  Fenwick_tree_dual(int n = 0) {
    build(n);
  }
  Fenwick_tree_dual(const vector<G>& a) {
    build(a);
  }
  void build(int n) {
    a.assign(n, G{});
  }
  void build(const vector<G>& a) {
    this->a = a;
    for (int i = 1; i <= a.size(); i++)
      if (i + (i & -i) <= a.size())
        (this->a)[i - 1] -= (this->a)[i + (i & -i) - 1];
  }
  void add(int l, int r, const G& val) {
    if (l == 0) {
      for (; r > 0; r -= r & -r) a[r - 1] += val;
      return;
    }
    add(0, r, val);
    add(0, l, -val);
  }
  G get(int i) const {
    G res{};
    for (i++; i <= a.size(); i += i & -i) res += a[i - 1];
    return res;
  }
};

int main() {
  int n;
  cin >> n;
  vector<int> l(n), r(n);
  rep (i, n) cin >> l[i] >> r[i];

  Fenwick_tree_dual<lint> F01(n + 1), F10(n + 1), F11(n + 1);
  rep (i, n) {
    lint x, y;
    // F01
    x = n - r[i];
    y = min(n - l[i], l[i] - 1);
    if (x <= y) F01.add(x, y + 1, 1);
    x = max(n - r[i], r[i] + 1);
    y = n - l[i];
    if (x <= y) F01.add(x, y + 1, 1);
    // F10
    x = l[i];
    y = min(r[i], n - r[i] - 1);
    if (x <= y) F10.add(x, y + 1, 1);
    x = max(l[i], n - l[i] + 1);
    y = r[i];
    if (x <= y) F10.add(x, y + 1, 1);
    // F11
    x = max(l[i], n - r[i]);
    y = min(r[i], n - l[i]);
    if (x <= y) F11.add(x, y + 1, 1);
  }

  mint ans = 0;
  rep (c, 1, n) {
    lint f01 = F01.get(c);
    lint f10 = F10.get(c);
    lint f11 = F11.get(c);
    lint f00 = n - f01 - f10 - f11;
    if (f00 > 0) continue;
    if (f10 > c || f10 + f11 < c) continue;
    ans += choose(f11, c - f10);
  }
  cout << ans << endl;

  return 0;
}
