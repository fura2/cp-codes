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

vector<mint> roots, iroots; // roots[i] = 1 の原始 2^i 乗根 in F_p

vector<mint> ntt(vector<mint> p, int dep, const vector<mint>& roots) {
  int n = p.size();
  assert(n == (1 << dep));
  if (n == 1) return p;

  vector<mint> p_even(n / 2), p_odd(n / 2);
  rep (i, n / 2) {
    p_even[i] = p[2 * i];
    p_odd[i] = p[2 * i + 1];
  }
  p_even = ntt(p_even, dep - 1, roots);
  p_odd = ntt(p_odd, dep - 1, roots);

  mint r = 1;
  rep (i, n) {
    p[i] = p_even[i % (n / 2)] + r * p_odd[i % (n / 2)];
    r *= roots[dep];
  }
  return p;
}

vector<mint> convolution(vector<mint> p, vector<mint> q) {
  int n = p.size(), m = q.size();
  int k = n + m - 1;

  int N;
  for (N = 1; N < k; N *= 2);
  int lgN = round(log2(N));
  p.resize(N, 0);
  q.resize(N, 0);

  auto p_hat = ntt(p, lgN, roots);
  auto q_hat = ntt(q, lgN, roots);

  vector<mint> r_hat(N);
  rep (i, N) r_hat[i] = p_hat[i] * q_hat[i];

  auto r = ntt(r_hat, lgN, iroots);
  r.resize(k);
  mint denom = mint(1) / N;
  rep (i, k) r[i] *= denom;
  return r;
}

mint bostan_mori(vector<mint> p, vector<mint> q, lint m) {
  for (; m > 0; m /= 2) {
    auto qm = q; // Q(-x)
    rep (i, 1, q.size(), 2) qm[i] *= -1;

    p = convolution(p, qm);
    rep (i, m % 2, p.size(), 2) p[i / 2] = p[i];
    p.resize((p.size() + (m + 1) % 2) / 2);

    q = convolution(q, qm);
    rep (i, 0, q.size(), 2) q[i / 2] = q[i];
    q.resize((q.size() + 1) / 2);
  }
  return p[0] / q[0];
}

int main() {
  roots.resize(24);
  iroots.resize(24);
  roots[23] = pow(mint(3), 119); // 1 の原始 23 乗根 in F_p
  iroots[23] = 1 / roots[23];
  rrep (i, 1, 24) {
    roots[i - 1] = roots[i] * roots[i];
    iroots[i - 1] = iroots[i] * iroots[i];
  }

  int n;
  lint m;
  cin >> n >> m;
  vector<int> a(n);
  rep (i, n) cin >> a[i];

  a.emplace_back(1);
  n++;

  lint sum = accumulate(all(a), 0LL);

  vector<mint> p = {1}, q(sum + 2);
  q[0] = 1;
  rep (i, n) {
    rrep (j, a[i], sum + 2) {
      q[j] -= q[j - a[i]];
    }
  }
  cout << bostan_mori(p, q, m) << endl;

  return 0;
}
