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

template<typename T>
constexpr int bit(T x, unsigned int k) {
  return (x >> k) & 1;
}

template<typename T>
constexpr bool chmax(T& a, const T& b) {
  return a < b ? a = b, true : false;
}
template<typename T>
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

#endif // TEMPLATE_HPP

__int128_t fib[90];
string x, y;
vector<lint> xpos[128], ypos[128];

__int128_t len(int i) {
  if (i == 0) return x.size();
  return fib[i - 1] * x.size() + fib[i] * y.size();
}

// S_i の先頭 n 文字に含まれる c の個数
__int128_t f(int i, char c, lint n) {
  if (i == 0) {
    return lower_bound(all(xpos[c]), n) - xpos[c].begin();
  }
  if (i == 1) {
    return lower_bound(all(ypos[c]), n) - ypos[c].begin();
  }
  if (len(i - 1) >= n) {
    return f(i - 1, c, n);
  }
  return fib[i - 2] * xpos[c].size() + fib[i - 1] * ypos[c].size()
         + f(i - 2, c, n - len(i - 1));
}

int main() {
  fib[0] = 0;
  fib[1] = 1;
  rep (i, 88) fib[i + 2] = fib[i + 1] + fib[i];

  int q;
  cin >> x >> y >> q;
  rep (i, x.size()) xpos[x[i]].emplace_back(i);
  rep (i, y.size()) ypos[y[i]].emplace_back(i);
  rep (_, q) {
    lint l, r;
    char c;
    cin >> l >> r >> c;
    cout << lint(f(89, c, r) - f(89, c, l - 1)) << endl;
  }

  return 0;
}
