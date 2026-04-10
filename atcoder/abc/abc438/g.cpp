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

template<class G>
class Fenwick_tree {
  vector<G> a;

 public:
  Fenwick_tree(int n = 0) {
    build(n);
  }
  Fenwick_tree(const vector<G>& a) {
    build(a);
  }
  void build(int n) {
    a.assign(n, G{});
  }
  void build(const vector<G>& a) {
    this->a = a;
    for (int i = 1; i <= a.size(); i++)
      if (i + (i & -i) <= a.size())
        (this->a)[i + (i & -i) - 1] += (this->a)[i - 1];
  }
  void add(int i, const G& val) {
    for (i++; i <= a.size(); i += i & -i) a[i - 1] += val;
  }
  G sum(int l, int r) const {
    if (l == 0) {
      G res{};
      for (; r > 0; r -= r & -r) res += a[r - 1];
      return res;
    }
    return sum(0, r) - sum(0, l);
  }
  int lower_bound(G val) const {
    if (!(G{} < val)) return 0;
    int x = 0, k;
    for (k = 1; k <= a.size(); k <<= 1);
    for (k >>= 1; k > 0; k >>= 1)
      if (x + k <= a.size() && a[x + k - 1] < val) val -= a[x + k - 1], x += k;
    return x;
  }
  int upper_bound(G val) const {
    if (val < G{}) return 0;
    int x = 0, k;
    for (k = 1; k <= a.size(); k <<= 1);
    for (k >>= 1; k > 0; k >>= 1)
      if (x + k <= a.size() && !(val < a[x + k - 1]))
        val -= a[x + k - 1], x += k;
    return x;
  }
};

// assume gcd(n, m) == 1 and 0 <= k < m * n and k mod n == 0
mint solve3(vector<lint> a, vector<lint> b, lint k) {
  lint n = a.size(), m = b.size();
  vector<lint> b2(m);
  rep (j, m) b2[j] = b[(n * j) % m];

  // i2j[i mod m] = j s.t. i mod m = (n * j) mod m
  vector<int> i2j(m);
  rep (j, m) i2j[(n * j) % m] = j;

  vector<int> p(m); // b2 の index の昇順
  iota(all(p), 0);
  sort(all(p), [&](int i, int j) { return b2[i] < b2[j]; });
  vector<int> pinv(m);
  rep (j, m) pinv[p[j]] = j;
  auto b2_sorted = b2;
  sort(all(b2_sorted));

  vector<pair<int, int>> ord(n); // (l, i)
  rep (i, n) ord[i] = {i2j[i % m], i};
  sort(all(ord));

  Fenwick_tree<mint> Fcnt(m), Fsum(m);
  int w = k / n;
  rep (j, w) {
    Fcnt.add(pinv[j], 1);
    Fsum.add(pinv[j], b2[j]);
  }

  mint res = 0;
  int cur = 0;
  rep (t, n) {
    auto [l, i] = ord[t];
    if (t == 0) assert(i == 0 && l == 0);
    while (cur < l) {
      Fcnt.add(pinv[cur], -1);
      Fsum.add(pinv[cur], -b2[cur]);
      Fcnt.add(pinv[(cur + w) % m], 1);
      Fsum.add(pinv[(cur + w) % m], b2[(cur + w) % m]);
      cur++;
    }
    int bdry = lower_bound(all(b2_sorted), a[i]) - b2_sorted.begin();
    res += Fsum.sum(0, bdry);
    res += a[i] * Fcnt.sum(bdry, m);
  }
  return res;
}

// assume gcd(n, m) == 1 and 0 <= k < m * n
mint solve2(vector<lint> a, vector<lint> b, lint k) {
  lint n = a.size(), m = b.size();
  mint res = 0;
  while (k % n != 0) {
    res += min(a[(k - 1) % n], b[(k - 1) % m]);
    k--;
  }
  return res + solve3(a, b, k);
}

// assume gcd(n, m) == 1
mint solve(vector<lint> a, vector<lint> b, lint k) {
  lint n = a.size(), m = b.size();
  auto a2 = a, b2 = b;
  sort(all(a2));
  sort(all(b2));
  mint res = 0;
  rep (i, n) res += a[i] * (b2.end() - lower_bound(all(b2), a[i]));
  rep (j, m) res += b[j] * (a2.end() - upper_bound(all(a2), b[j]));
  return (k / (m * n)) * res + solve2(a, b, k % (m * n));
}

mint naive(vector<lint> a, vector<lint> b, lint k) {
  lint n = a.size(), m = b.size();
  lint ans = 0;
  rep (i, k) ans += min(a[i % n], b[i % m]);
  return ans;
}

int main() {
  lint n, m;
  lint k;
  cin >> n >> m >> k;
  vector<lint> a(n), b(m);
  rep (i, n) cin >> a[i];
  rep (j, m) cin >> b[j];

  int g = gcd(n, m);
  mint ans = 0;
  rep (t, g) {
    vector<lint> a2, b2;
    rep (i, t, n, g) a2.emplace_back(a[i]);
    rep (j, t, m, g) b2.emplace_back(b[j]);
    ans += solve(a2, b2, k / g + (t < k % g ? 1 : 0));
  }
  cout << ans << endl;

  return 0;
}
