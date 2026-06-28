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

template <typename T>
constexpr int bit(T x, unsigned int k) {
  return (x >> k) & 1;
}

template <typename T>
constexpr bool chmax(T& a, const T& b) {
  return a < b ? a = b, true : false;
}
template <typename T>
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

#endif  // TEMPLATE_HPP

class mint {
  static const int MOD = 998244353;
  int x;

 public:
  mint(): x(0) {
  }
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

lint f(const vector<int>& p) {
  int n = p.size();
  lint cum = 0;
  rrep (x, n) {
    int pos = find(all(p), x) - p.begin();
    int res = cum;
    if (*max_element(p.begin(), p.begin() + pos + 1) > x) res += 1;
    cum += res;
  }
  return cum;
}

void naive() {
  int n, k;
  cin >> n >> k;
  vector<int> a(k);
  rep (i, k) cin >> a[i], a[i]--;

  vector<int> p(n);
  iota(all(p), 0);
  mint ans = 0;
  do {
    if (!equal(all(a), p.begin())) continue;
    ans += f(p);
  } while (next_permutation(all(p)));
  cout << ans << endl;
}

void solve() {
  int n, k;
  cin >> n >> k;
  vector<int> a(k);
  rep (i, k) cin >> a[i], a[i]--;

  vector<int> pos(n, -1);
  rep (i, k) pos[a[i]] = i;

  vector<int> acum(k + 1, -1);
  rep (i, k) chmax(acum[i + 1], max(acum[i], a[i]));

  // dp[x] = (n, n-1, ..., x まで決めたときの, 可能な数列 σ に対する f(σ) の和)
  vector<mint> dp(n + 1);
  // way[x] = (n, n-1, ..., x まで決めたときの, 可能な数列の個数)
  vector<mint> way(n + 1);
  way[n] = 1;
  int cnt = 1;
  rrep (x, n) {
    int t1;  // 左に自身 (x) より大きい要素があるような, 挿入できる場所の個数
    int t2;  // 左に自身 (x) より大きい要素がないような, 挿入できる場所の個数
    if (pos[x] == -1) {
      if (acum[k] > x) {
        t1 = cnt;
        t2 = 0;
      }
      else {
        // 最左に挿入するときは f の値が +1 されない
        t1 = cnt - 1;
        t2 = 1;
      }
      cnt++;
    }
    else {
      if (acum[pos[x]] > x) {
        t1 = 1;
        t2 = 0;
      }
      else {
        t1 = 0;
        t2 = 1;
      }
    }
    dp[x] = (t1 + t2) * dp[x + 1];  // x より大きい要素からの寄与
    dp[x] += t1 * way[x + 1] + (t1 + t2) * dp[x + 1];  // x からの寄与
    way[x] = (t1 + t2) * way[x + 1];
  }
  cout << dp[0] << endl;
}

int main() {
  int t;
  cin >> t;
  // rep (_, t) naive();
  rep (_, t) solve();
  return 0;
}
