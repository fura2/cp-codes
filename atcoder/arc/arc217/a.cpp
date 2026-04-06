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

void solve() {
  int n;
  cin >> n;

  // auto f = [&](const vector<int>& p) -> int {
  //   int res = 0, cum = 0;
  //   rep (i, n) {
  //     cum ^= p[i];
  //     res += cum;
  //   }
  //   return res;
  // };

  // vector<int> p(n);
  // iota(all(p), 1);
  // int mn = 100000000;
  // vector<vector<int>> S;
  // do {
  //   int x = f(p);
  //   if (x < mn) {
  //     mn = x;
  //     S = {p};
  //   }
  //   else if (x == mn) {
  //     S.emplace_back(p);
  //   }
  // } while (next_permutation(all(p)));

  // show(mn);
  // show(S);

  auto f = [](auto f, int n) -> vector<int> {
    if (n == 0) return {0};
    if (n == 1) return {0, 1};
    if (n == 2) return {0, 1, 2};
    if (n == 3) return {0, 1, 3, 2};

    int b;
    for (b = 20; b >= 0; b--) {
      if (bit(n, b) == 1) break;
    }
    auto l = f(f, (1 << b) - 1);
    auto r = f(f, n - (1 << b));
    for (auto& x: r) x += 1 << b;
    l.insert(l.end(), all(r));
    return l;
  };

  vector<int> ans = f(f, n);
  rep (i, n) cout << ans[i + 1] << " ";
  cout << "\n";
}

int main() {
  int t;
  cin >> t;
  rep (_, t) solve();
  return 0;
}
