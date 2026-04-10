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

template<class T>
vector<pair<T, int>> run_length_encoding(const vector<T>& a) {
  vector<pair<T, int>> res;
  int n = a.size(), pre = 0;
  rep (i, n)
    if (i == n - 1 || a[i] != a[i + 1])
      res.emplace_back(a[i], i - pre + 1), pre = i + 1;
  return res;
}

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  rep (i, n) cin >> a[i];

  vector<pair<int, int>> res;
  for (auto [c, k]: run_length_encoding(a)) {
    if (!res.empty() && res.back().first == c) {
      res.back().second += k;
    }
    else {
      res.emplace_back(c, k);
    }
    res.back().second %= 4;
    if (res.back().second == 0) {
      res.pop_back();
    }
  }

  int ans = 0;
  for (auto [c, k]: res) ans += k;
  cout << ans << endl;

  return 0;
}
