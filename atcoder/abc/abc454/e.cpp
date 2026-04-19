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

// 対角線で反転
char transpose(char c) {
  switch (c) {
    case 'R':
      return 'D';
    case 'U':
      return 'L';
      break;
    case 'L':
      return 'U';
    case 'D':
      return 'R';
  }
  assert(false);
}

// Assume n: even, m: even, a+b: odd
string f(int n, int m, int a, int b) {
  if (a == 0) {
    string res;
    rep (j, 0, b, 2) {
      res += "DR";
      if (j < b - 2) res += "UR";
    }
    rep (j, b, m - 2, 2) {
      res += "RURD";
    }
    rep (i, 2, n, 2) {
      res += "D";
      res += string(m - 1, 'L');
      res += "D";
      res += string(m - 1, 'R');
    }
    return res;
  }

  if (b == 0) {
    string res = f(m, n, b, a);
    for (char& c: res) c = transpose(c);
    return res;
  }

  if (a >= 2) {
    string res;
    res += string(m - 1, 'R');
    res += "D";
    res += string(m - 1, 'L');
    res += "D";
    return res + f(n - 2, m, a - 2, b);
  }

  if (b >= 2) {
    string res;
    res += string(n - 1, 'D');
    res += "R";
    res += string(n - 1, 'U');
    res += "R";
    return res + f(n, m - 2, a, b - 2);
  }

  assert(false);
}

void solve() {
  int n, a, b;
  cin >> n >> a >> b;
  a--, b--;

  if (n % 2 == 1 || (a + b) % 2 == 0) {
    no();
    return;
  }

  yes();
  cout << f(n, n, a, b) << "\n";
}

int main() {
  int t;
  cin >> t;
  rep (_, t) solve();
  return 0;
}
